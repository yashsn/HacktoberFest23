package main

import (
	"fmt"
	"math/rand"
	"time"

	"github.com/nsf/termbox-go"
)

const (
	screenW = 30
	screenH = 20
)

type Point struct {
	X int
	Y int
}

var (
	snake    []Point
	dir      Point
	food     Point
	score    int
	gameOver bool
)

func placeFood() {
	food = Point{rand.Intn(screenW), rand.Intn(screenH)}
}

func moveSnake() {
	head := snake[0]
	newHead := Point{head.X + dir.X, head.Y + dir.Y}

	if newHead.X < 0 || newHead.Y < 0 || newHead.X >= screenW || newHead.Y >= screenH {
		gameOver = true
		return
	}

	for _, p := range snake[1:] {
		if p == newHead {
			gameOver = true
			return
		}
	}

	snake = append([]Point{newHead}, snake...)

	if newHead == food {
		score++
		placeFood()
	} else {
		snake = snake[:len(snake)-1]
	}
}

func draw() {
	termbox.Clear(termbox.ColorDefault, termbox.ColorDefault)

	for _, p := range snake {
		termbox.SetCell(p.X, p.Y, 'O', termbox.ColorGreen, termbox.ColorDefault)
	}
	termbox.SetCell(food.X, food.Y, '*', termbox.ColorRed, termbox.ColorDefault)

	scoreStr := fmt.Sprintf("Score: %d", score)
	for i, c := range scoreStr {
		termbox.SetCell(i, screenH, c, termbox.ColorWhite, termbox.ColorDefault)
	}

	termbox.Flush()
}

func initGame() {
	snake = []Point{
		{screenW / 2, screenH / 2},
		{screenW/2 - 1, screenH / 2},
		{screenW/2 - 2, screenH / 2},
	}
	dir = Point{1, 0}
	placeFood()
	score = 0
	gameOver = false
}

func main() {
	err := termbox.Init()
	if err != nil {
		panic(err)
	}

	defer termbox.Close()
	rand.Seed(time.Now().UnixNano())
	initGame()

	go func() {
		for {
			if gameOver {
				break
			}
			moveSnake()
			draw()
			time.Sleep(100 * time.Millisecond)
		}
	}()

	for {
		if gameOver {
			fmt.Println("Game Over! Score is:", score)
			break
		}

		switch ev := termbox.PollEvent(); ev.Type {
		case termbox.EventKey:
			switch ev.Key {
			case termbox.KeyArrowUp:
				if dir.Y == 0 {
					dir = Point{0, -1}
				}
			case termbox.KeyArrowDown:
				if dir.Y == 0 {
					dir = Point{0, 1}
				}
			case termbox.KeyArrowLeft:
				if dir.X == 0 {
					dir = Point{-1, 0}
				}
			case termbox.KeyArrowRight:
				if dir.X == 0 {
					dir = Point{1, 0}
				}
			case termbox.KeyEsc:
				gameOver = true
			}
		}
	}
}
