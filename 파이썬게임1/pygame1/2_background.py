import pygame
pygame.init() #초기화 반드시 필요함

# 화면 크기 설정
screen_width = 480
screen_height = 640
screen = pygame.display.set_mode((screen_width,screen_height))

#화면 타이틀 설정
pygame.display.set_caption("EL Game")#게임 이름

#배경 이미지 불러오기1
background = pygame.image.load("C:\\Users\\Administrator\\Desktop\\나도코딩파이썬\\나도코딩파이썬게임\\background.png")

#  이벤트 루프
running = True #게임이 진행중인가?
while running:
    for event in pygame.event.get(): #어떤 이벤트가 발생하였는가?
        if event.type == pygame.QUIT: #창이 닫히는 이벤트가 발생하였는가?
            running = False #게임이 진행중이 아니다.

    # screen.fill((0,0,255)) #배경을 단색으로 채운다.

    screen.blit(background,(0,0)) #배경이 나타날 지점 설정        

    pygame.display.update() # 게임화면을 다시 그린다.
#pygame 종료
pygame.quit()


