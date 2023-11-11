#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{

    system("color 9F"); //This gives the terminal a color and the text on the screen.
    system("title GUESS THE NUMBER   @AkashAnuragi"); //This sets the text on the terminal
    int user_input,secret_number,c=0,wrong_attempts=0;
    int current_score=0, maximum_score=0;
    int num_of_rounds;
    int choice;
    cout << "\t\t\t<==================================================================>" << endl;
    cout << "\t\t\t|                 Welcome to the number guessing Game              |" << endl;
    cout << "\t\t\t<==================================================================>" << endl;
    cout << endl << endl << endl;
    cout << "\t\t\tchoose from below options" << endl;
    cout << "\t\t\t [1] Know Game Rules" << endl;
    cout << "\t\t\t [2] Play the game" << endl;
    cin >> choice;
    if(choice == 1){
        system("cls");
        cout << "\t\t\t<==================================================================>" << endl;
        cout << "\t\t\t|                 Welcome to the number guessing Game              |" << endl;
        cout << "\t\t\t<==================================================================>" << endl << endl << endl;
        cout << "\tChoose the number of rounds you want to play from 1-10" << endl;
        cout << "\tIn each round, you have to guess the secret number correctly" << endl;
        cout << "\tIf you guess the secret number in first attempt, you get 10 points" << endl;
        cout << "\tIf you guess the secret number in second attempt, you get 5 points" << endl;
        cout << "\tIf you guess the secret number in third attempt, you get 3 points" << endl;
        cout << "\tIf you guess the secret number in after third attempt, you get only 1 point" << endl;
    }
        cout << endl << endl;
        char ch;
        do
        {
            cout << "\t Please enter number of rounds you want to play this game (1-5)" << endl;
            cin >> num_of_rounds;
            current_score = 0;
            wrong_attempts = 0;
            // this loop run for the number of rounds the user wants to play
            for(int i=0; i<num_of_rounds; i++){
                secret_number=rand()%10+1; // generate a random secret number in the range 1-10

                // until the user doesn't find the right answer keep on asking and checking
                while(secret_number != user_input)
                {
                    cout<<"\t Enter your guess between 1-10 "<<endl;
                    cin >> user_input;
                    cout<<endl;
                    if(user_input < secret_number){
                        cout << "\t Your guess is low, guess higher!!!" << endl;
                        wrong_attempts++;
                    }
                    else if(user_input > secret_number)
                    {
                        cout<<"\t Your guess is high, guess lower!!!"<<endl;
                        wrong_attempts++;
                    }
                }

                //when the user has guessed it right, check how quickly the number was found and give points accordingly
                cout<<"\t Congratulations your guess is correct"<<endl << endl;
                cout<<"\t You guessed wrong numbers " << wrong_attempts << " times" << endl << endl; //show how many times the number was guessed wrong

                //if there is next round still remaining then show message
                if(i!=num_of_rounds-1){
                    cout << "\t Let's start next round" << endl;
                }
                cout << endl << endl;
                    if(wrong_attempts == 0){
                        current_score = current_score + 10;
                    }
                    else if(wrong_attempts == 1){
                        current_score = current_score + 5;
                    }
                    else if(wrong_attempts == 2){
                        current_score = current_score + 3;
                    }
                    else{
                        current_score = current_score + 1;
                    }
            }

            //set the high score if it's greater than previous score
            if(current_score > maximum_score){
                maximum_score = current_score;
            }
            system("cls");
            cout << "\t\t\t You have completed all the rounds" << endl;
            cout << "\t\t\t Your current score is: " << current_score << endl;
            cout << "\t\t\t Highest score: " << maximum_score << endl << endl << endl;
            cout<<"Do you want to play again yes/no : ";
            cin >> ch;
            cout<<endl;
            if(ch !='no' && ch !='yes'){
                cout << "\tWrong Input, Please enter yes/no : " << endl;
            }
            system("cls");
            cout << "\t\t\t<==================================================================>" << endl;
            cout << "\t\t\t|                 Welcome to the number guessing Game              |" << endl;
            cout << "\t\t\t<==================================================================>" << endl;
        }while(ch!='n');
}
