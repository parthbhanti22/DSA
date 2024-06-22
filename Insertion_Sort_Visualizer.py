import pygame
import random
import winsound

pygame.init()

WIDTH = 800
HEIGHT = 600
BLUE = (0, 0, 255)
HIGHLIGHT = (255, 0, 0)

window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Insertion Sort Visualization")

def draw_bars(window, arr, current=None, key_pos=None):
    bar_width = WIDTH // len(arr)
    for i in range(len(arr)):
        bar_height = arr[i] * 5
        if i == current:
            pygame.draw.rect(window, HIGHLIGHT, (i * bar_width, HEIGHT - bar_height, bar_width, bar_height))
        elif i == key_pos:
            pygame.draw.rect(window, (0, 255, 0), (i * bar_width, HEIGHT - bar_height, bar_width, bar_height))
        else:
            pygame.draw.rect(window, BLUE, (i * bar_width, HEIGHT - bar_height, bar_width, bar_height))

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            draw_bars(window, arr, current=j, key_pos=i)
            pygame.display.update()
            pygame.time.delay(100)
            winsound.Beep(440, 100)
            j -= 1
        arr[j + 1] = key
        draw_bars(window, arr, current=j, key_pos=i)
        pygame.display.update()
        pygame.time.delay(100)

def main():
    running = True
    clock = pygame.time.Clock()

    arr = [random.randint(1, HEIGHT // 5) for _ in range(50)]

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        window.fill((0, 0, 0))
        draw_bars(window, arr)
        pygame.display.update()

        insertion_sort(arr)
        
        pygame.time.delay(3000)
        running = False

        clock.tick(60)

    pygame.quit()

if __name__ == "__main__":
    main()
