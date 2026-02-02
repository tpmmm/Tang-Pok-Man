def start():

    import random 

    shapes = ('r', 'p', 's')

    score = 0

    run = True

    while run:

        opponent = random.choice(shapes)
        player = None

        while player not in shapes:
            player = input('choose a shape (r, p, s): ')
            if player not in shapes:
                print('Invalid input.')

        print(f'player: {player}')
        print(f'opponent: {opponent}')

        if player == opponent:
            print('draw')

        elif player == 'r' and opponent == 's':
            print('you win!')
            score += 1

        elif player == 'p' and opponent == 'r':
            print('you win!')
            score += 1

        elif player == 's' and opponent == 'p':
            print('you win!')
            score += 1

        else:
            print('you lose')
            print(f'score: {int(score)}')
            run = False

    again = input('again? (y/n)\n')

    if again == 'y':
        start()

    else:
        print('fin!')

start()

