dir1 = 'север'
dir2 = 'восток'
dir3 = 'юг'
dir4 = 'запад'

k = 0
x = 0
y = 0
dir0 = dir1
xt = int(input())
yt = int(input())
while x != xt or y != yt:
    k += 1
    inp = input()
    if inp == 'вперёд':
        inp = int(input())
        if dir0 == dir1:
            y += inp
        elif dir0 == dir2:
            x += inp
        elif dir0 == dir3:
            y -= inp
        elif dir0 == dir4:
            x -= inp
        else:
            print('ошибка')
    elif inp == 'налево':
        if dir0 == dir1:
            dir0 = dir4
        elif dir0 == dir2:
            dir0 = dir1
        elif dir0 == dir3:
            dir0 = dir2
        elif dir0 == dir4:
            dir0 = dir3
        else:
            print('ошибка')
    elif inp == 'направо':
        if dir0 == dir1:
            dir0 = dir2
        elif dir0 == dir2:
            dir0 = dir3
        elif dir0 == dir3:
            dir0 = dir4
        elif dir0 == dir4:
            dir0 = dir1
        else:
            print('ошибка')
    elif inp == 'разворот':
        if dir0 == dir1:
            dir0 = dir3
        elif dir0 == dir2:
            dir0 = dir4
        elif dir0 == dir3:
            dir0 = dir1
        elif dir0 == dir4:
            dir0 = dir2
        else:
            print('ошибка')
    else:
        print('ошибка, введите корректную комманду')
print(k)
print(dir0)
