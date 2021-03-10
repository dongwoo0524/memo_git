import pygame
import random
pygame.init() #초기화 반드시 필요함

# 화면 크기 설정
screen_width = 480
screen_height = 640
screen = pygame.display.set_mode((screen_width,screen_height))

#화면 타이틀 설정
pygame.display.set_caption("EL Game")#게임 이름

#FPS
clock = pygame.time.Clock()

#배경 이미지 불러오기1
background = pygame.image.load("C:\\Users\\Administrator\\Desktop\\나도코딩파이썬\\나도코딩파이썬게임\\background.png")

#(캐릭터) 스프라이트 불러오기
character = pygame.image.load("C:\\Users\\Administrator\\Desktop\\나도코딩파이썬\\나도코딩파이썬게임\\char1.png")
character_size = character.get_rect().size #이미지의 크기를 구해옴
character_width = character_size[0] #캐릭터의 가로크기
character_height = character_size[1] #캐릭터의 세로크기
character_x_pos = screen_width/2 - character_width/2 #화면 가로의 절반 크기, 캐릭터의 처음 x위치
character_y_pos = screen_height  - character_height#화면 세로크기 가장 아래에 해당하는 곳에 위치

#이동할 좌표
to_x = 0


#이동속도
character_speed = 0.5\

#적 enemy
enemy = pygame.image.load("C:\\Users\\Administrator\\Desktop\\나도코딩파이썬\\나도코딩파이썬게임\\enemy1.png")
enemy_size = enemy.get_rect().size #이미지의 크기를 구해옴
enemy_width = enemy_size[0] #캐릭터의 가로크기
enemy_height = enemy_size[1] #캐릭터의 세로크기
enemy_x_pos =  random.randint(0,screen_width - enemy_width)
enemy_y_pos = 0

# 폰트 정의
game_font = pygame.font.Font(None,40) #폰트 객체 생성(폰트,크기)

# 총 시간
total_time = 10

#시작 시간 정보
start_ticks = pygame.time.get_ticks()

# 적이 공격하는 속도
attack_speed = 0.8

#  이벤트 루프
running = True #게임이 진행중인가?
while running:
    
    dt = clock.tick(30) #게임화면의 초당 프레임 수 설정

    print("fps : "+str(clock.get_fps()))

    for event in pygame.event.get(): #어떤 이벤트가 발생하였는가?
        if event.type == pygame.QUIT: #창이 닫히는 이벤트가 발생하였는가?
            running = False #게임이 진행중이 아니다.

        if event.type==pygame.KEYDOWN: #키가 눌렸는지 확인
            if event.key==pygame.K_LEFT:
                to_x-= character_speed
            elif event.key==pygame.K_RIGHT:
                to_x += character_speed


        if event.type == pygame.KEYUP: #방향키를 떼면 멈춤
            if event.key == pygame.K_LEFT or event.key==pygame.K_RIGHT:
                to_x = 0


    character_x_pos += to_x*dt
    enemy_y_pos += attack_speed*dt

#가로 경계값 처리
    if character_x_pos < 0:
        character_x_pos = 0
    elif character_x_pos > screen_width - character_width:
        character_x_pos = screen_width - character_width

    #충돌처리
    character_rect = character.get_rect()
    character_rect.left = character_x_pos #실시간으로 위치 업데이트
    character_rect.top = character_y_pos

    enemy_rect = enemy.get_rect()
    enemy_rect.left = enemy_x_pos
    enemy_rect.top = enemy_y_pos

    if character_rect.colliderect(enemy_rect): #충돌처리 함수 colliderect
        print("충돌!!")
        running = False

    if enemy_y_pos>=screen_height+enemy_height:
        enemy_x_pos =  random.randint(0,screen_width - enemy_width)
        enemy_y_pos = 0

    screen.blit(background,(0,0)) #배경이 나타날 지점 설정        
    screen.blit(character,(character_x_pos,character_y_pos)) #캐릭터가 나타날 지점 설정
    screen.blit(enemy,(enemy_x_pos,enemy_y_pos)) #적 그리기

    #타이머 집어 넣기
    #경과 시간 계산
    elapsed_time = (pygame.time.get_ticks() - start_ticks)/1000
    #경과 시간을 (ms) 1000으로 나누어서 초 단위로 표시

    timer = game_font.render(str(int(total_time - elapsed_time)),True,(255,255,255))
    # 출력할 글자,시간, True, 글자색상

    screen.blit(timer,(10,10))

    #만약 시간이 0 이하이면 게임 종료
    if total_time - elapsed_time<=0:
        print("TIME OVER")
        running = False
    
    pygame.display.update() # 게임화면을 다시 그린다.

#잠시 대기
pygame.time.delay(2000)
#pygame 종료
pygame.quit()


