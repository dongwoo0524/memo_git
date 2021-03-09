gun  = 10

def checkpoint(soldiers):
    global gun #전역 공간에 있는 gun 사용한다 권장되지는 않음
    gun  = gun-soldiers
    print("남은 총 : {}".format(gun))

def checkpoint_ret(gun,soldiers):
    gun = gun - soldiers
    print("남은 총 : {}".format(gun))
    return gun

print("전체 총 : {}".format(gun))
# checkpoint(2)
gun = checkpoint_ret(gun,2) #리턶한 값을 다시 저장해준다.
print("전체 총 : {}".format(gun))