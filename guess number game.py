def main():

    begin = input('type start to begin: ')

    if begin == 'start':
        def game():

            import random

            answer = random.randint(1,100)

            guess = 0

            lower_bound = 1
            upper_bound = 100
            print(f'range: {lower_bound} - {upper_bound}')

            while guess != answer:

                guess = int(input('guess a number: ') )
                if int(guess)>int(answer):
                    print(f'the answer is smaller than {int(guess)}.')
                    upper_bound = int(guess-1)
                    if int(lower_bound) == int(upper_bound):
                        print (f'range: {lower_bound}')
                    else: 
                        print(f'range: {lower_bound} - {upper_bound}')
                    print('guess again')
                    
                elif int(guess)<int(answer):
                    print(f'the answer is larger than {int(guess)}.')
                    lower_bound = int(guess+1)
                    if int(lower_bound) == int(upper_bound):
                        print (f'range: {lower_bound}')
                    else: 
                        print(f'range: {lower_bound} - {upper_bound}')
                    print('guess again')

                else: 
                    print('correct!')

            again =  input('play another round?\n')

            if again == 'yes':
                game()
            
            else: 
                print('the end')
        game()
main()