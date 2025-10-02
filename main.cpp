/* ETHAN ORMES CSCI 200 section F ENIGMA MACHINE - This code allows the user to create an enigma machine, chosing from a handful of preset rotors and reflectors to encode and decode messages from files.
* 
*
*
*/

#include "Exchangeable.h"
#include "InputProcessor.h"
#include "OutputProcessor.h"
#include "Rotor.h"
#include "Machine.h"
#include <iostream>
#include <limits>
using namespace std;
int main()
{
    bool gameLoop = true;
    Machine enigma = Machine();
    
    cout << "Welcome to my enigma machine." << endl;

    //Adding rotors
    int numRotors = 0;
    while (true)
    {
        cout << "How many rotors would you like to use?" << endl;
        cin >> numRotors;

        // Check if the input is an integer and within the valid range
        if (!cin.fail() && numRotors > 0 && numRotors <= 6 && cin.peek() == '\n')
        {
            break;
        }
        cout << "Please enter a valid number. (a positive integer)." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for(int i = 0;i < numRotors; i++)
    {
        int rotorPreset;
        while(true)
        {
            
            cout << "Please enter a rotor preset you would like to use. (1-6)" << endl;
            cin >> rotorPreset;
            if(!cin.fail() && rotorPreset > 0 && rotorPreset < 7 && cin.peek() == '\n')
            {
                break;
            }
            cout << "Please enter a valid number. (an integer from 1-6)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    
        }
        int notchPreset;
        while(true)
        {
            cout << "Please enter an initial notch position for this rotor you would like to use." << endl;
            cin >> notchPreset;
            if(!cin.fail() && cin.peek() == '\n')
            {
                break;
            }
            cout << "Please enter a valid number. (any integer)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    
        }
        while(notchPreset < 0)
        {
            notchPreset += 26;
        }
        Rotor rotor = Rotor(rotorPreset,notchPreset);
        enigma.addRotor(rotor);
    }


    //Adding plugboard
    PlugBoard plugboard = PlugBoard();
    int numSwitches;
    char letter1;
    char letter2;
    while(true)
    {
        cout << "Now how many pairs would you like to connect on the plug board? (0-10)" << endl;
        cin >> numSwitches;
        if(!cin.fail() && cin.peek() == '\n' && numSwitches >= 0 && numSwitches <= 10)
        {
            break;
        }
        cout << "Please enter a valid number. (an integer from 0 - 10)" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(numSwitches < 0)
    {
        numSwitches = 0;
    }
    if(numSwitches > 10)
    {
        numSwitches = 10;
    }
    for(int i = 0; i < numSwitches; i++)
    {
        while(true)
        {
            cout << "Enter the first letter you would like to switch. (A-Z)" << endl;
            cin >> letter1;
            cout << "Enter the second letter you would like to switch. (A-Z)" << endl;
            cin >> letter2;
            if(cin.fail() || cin.peek() != '\n' || letter1 < 'A' || letter1 > 'Z' || letter2 < 'A' || letter2 > 'Z')
            {
                cout << "At least one letter was entered improperly" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                if(plugboard.set(letter1,letter2))
                {
                    cout << "Conntected " << letter1 << " to " << letter2 << endl;
                    break;
                }
                else
                {
                    cout << "One of those letters is already plugged in. Please try another." << endl;
                }
            }
            
        }
    }
    enigma.addPlugBoard(plugboard);


    //Adding a reflector
    PlugBoard reflector = PlugBoard();
    int reflectorPreset;
    while(true)
    {
        
        cout << "Choose a reflector preset(1-3)" << endl;
        cin >> reflectorPreset;
        if(cin.fail() || cin.peek() != '\n' || reflectorPreset < 1 || reflectorPreset > 3)
        {
            cout << "Please enter a valid number (an ineger from 1-3)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            reflector = PlugBoard(reflectorPreset);
            break;
        }
    }
    enigma.addReflector(reflector);
    while (gameLoop)
    {
        

        //File input
        InputProcessor in = InputProcessor();
        while(!in.openStream())
        {}
        in.read();

        //Encoding
        vector<char> letters = in.getLetters();
        for(unsigned int i = 0; i < letters.size(); i++)
        {
            letters.at(i) = enigma.exchange(letters.at(i));
        }

        //File output
        OutputProcessor out = OutputProcessor();
        while(!out.openStream())
        {}
        out.writeFrom(letters);
        out.closeStream();

        char decision;
        while(true)
        {
            cout << "Would you like to encode another message with the same machine? (Y/N)";
            cin >> decision;
            if(decision == 'y' || decision == 'Y')
            {
                break;
                enigma.resetRotors();
            }
            else if(decision == 'n' || decision == 'N')
            {
                cout << "Thank you" << endl;
                break;
                gameLoop = false;
            }
            else
            {
                cout << "Please enter a valid choice" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}