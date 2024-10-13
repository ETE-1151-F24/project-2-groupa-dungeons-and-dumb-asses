#include <iostream>
#include <cstdlib>
using namespace std;

class stats { // Basic stats for all classes
    public:
    int hp;
    int luc;
    int str;
    int mp;
    int wpn;

};

int equHP (string array[], int HP) // Changes HP stat when new Tarot is equiped, Parameters include players inventory and current stat
{
    int const oHP = HP;


    for (size_t i = 0; i < 3; i++)
    {
        if (array[i] == "Lovers")
        {
            HP = HP*2;
        }else if (array[i] == "Death")
        {
            HP = HP/2;
        }
    }
    return HP;
    
}

int equStr (string array[], int Str)// Changes Str stat when new Tarot is equiped, Parameters include players inventory and current stat
{
    int const oStr = Str;

    for (size_t i = 0; i < 3; i++)
    {
       if (array[i] == "Devil")
        {
            Str = 10;
        }else if (array[i] == "Fool")
        {
            Str = Str +1;
        }else if (array[i] == "Strength")
        {
            Str = Str +2;
        }else if (array[i] == "Death")
        {
            Str = Str*2 +20;
        }else if (array[i] == "Master of the Art")
        {
            Str = Str +3;
        }
    }
    return Str;
    
}

int equLuc (string array[], int Luc)// Changes Luc stat when new Tarot is equiped, Parameters include players inventory and current stat
{
    int const oLuc = Luc;

    for (size_t i = 0; i < 3; i++)
    {
        if (array[i] == "Wheel of Fortune")
        {
            Luc = Luc +5;
        }else if (array[i] == "Devil")
        {
            Luc = 0;
        }else if (array[i] == "Rabbit's Foot")
        {
            Luc = Luc +3;
        }
    }
    return Luc;
}

int equMP (string array[], int MP)// Changes MP stat when new Tarot is equiped, Parameters include players inventory and current stat
{
    int const oMP = MP;

    for (size_t i = 0; i < 3; i++)
    {
        if (array[i] == "Magician")
        {
            MP = MP +5;
        }else if (array[i] == "Divine Curse")
        {
            MP = MP +3;
        }
    }
    return MP;
    
}

int main ()
{
    int choice =1;
    int c2 = 1; // choice 2
    int c3 =1; // choice 3
    int door = 0;
    string costume {"Pajamas"}; // Costume which are my different classes
    string bag [3] {"Empty", "Empty", "Empty"};
    string const items [2] [10]  {{"Wheel of Fortune", "Lovers", "Devil", "Fool", "Strength", "Master of the Art", "Rabbit's Foot", "Magician", "Divine Curse", "Death"}, {"+5 Luc", "HP*2", "Str = 10 Luc = 0", "+1 Str", "+2 Str", "+3 Str", "+3 Luc", "+5 MP", "+3 MP", "HP/2 Str = 20 +Str*2 (Burns Tarot Cards)"}};
    // The two dimensional array holds both the item name as well as their description, [0] holding item name and [1] holding item description
    
    stats user; // user stats
    user.hp = 20;
    user.luc = 1;
    user.str = 1;
    user.mp =10;


    stats Base; // base stats
    Base.hp = 20;
    Base.luc = 1;
    Base.str = 1;
    Base.mp =10;

    stats BLDR; //Blunderbuss stats
    BLDR.hp = 20;
    BLDR.luc = 0;
    BLDR.str = 2;
    BLDR.mp =10;
    
    stats JDG; //Judgement(Karen) stats
    JDG.hp = 20;
    JDG.luc = 3;
    JDG.str = 1;
    JDG.mp =8;
    
    stats CB;//Cyberbullying stats
    CB.hp = 10;
    CB.luc = 1;
    CB.str = 1;
    CB.mp =20;

    cout << "Hello and good morning";
    while (choice != 0)// start of sentinal loop
    {
        cout << "[What would you like to do]:\n0:Go Back to sleep \n1:Check out inventory\n2:Check out folder \n3:Check out closet\n4:Checkout door\n[0/1/2/3/4]";
        cin >> choice;
        
        switch (choice)
        {
            case 0: // Choice 0 Go back to sleep
                cout << "Okay goodbye, rest well\n";
                return 0;//ends program
            break; // End of Choice 0
            case 1:// Choice 1 Check inventory
                cout << "Inventory:\n";
                for (size_t i = 0; i < 3; i++) // for loop to display the users inventory
                {
                    cout << i+1 << ": " << bag[i] << endl;
                }
                if (bag[0] == "Empty" && bag[1] == "Empty" && bag[2] == "Empty") //checks if all slots of bag are "Empty"
                {
                    cout << "You felt nothing, You are full of Emptiness\n";
                }
                cout << "Your Stats are: \n"; // Displays stats
                cout << "HP: " << user.hp << endl;
                cout << "Luc: " << user.luc<< endl;
                cout << "Str: " << user.str<< endl;
                cout << "MP: " << user.mp<< endl;
                
                if (bag[0] != "Empty" || bag[1] != "Empty" || bag[2] != "Empty") //checks if all slots of bag are not "Empty"
                {
                    cout << "Would you like to take out an item )0:No 1:Yes\n";
                    cin >> c2;
                    if (c2 == 1)// if statement to decide if the user wants to remove an item from their inventory
                    {
                        while (c2 !=0){// sentinal loop to be able to remove more than one item if the user wants
                            for (size_t i = 0; i < 3; i++)
                            {
                                cout << i+1 << ": " << bag[i] << endl;
                            }
                            cout << "Which item would you like to get rid of (0:To Cancel) [0/1/2/3]:\n";
                            cin >> c2;
                            if (c2 > 0 && c2 < 4) // uses var - 1 to ensure that the right item in the array is selected
                            {
                                if (bag[c2-1] == "Empty")
                                {
                                    cout << "You can not get rid of emptiness\n";
                                }else
                                {
                                    cout << bag [c2 - 1] << " has been returned to the folder\n";
                                    bag [c2 -1] = "Empty";
                                }
                            }
                        }
                        if (costume == "Pajamas") // checks players class to ensure the right stats are being modified
                        {
                            user.hp = equHP(bag, Base.hp);
                            user.str = equStr(bag, Base.str);
                            user.luc = equLuc(bag, Base.luc);
                            user.mp = equMP(bag, Base.mp);
                        }else if (costume == "Sheriff")
                        {
                            user.hp = equHP(bag, BLDR.hp);
                            user.str = equStr(bag, BLDR.str);
                            user.luc = equLuc(bag, BLDR.luc);
                            user.mp = equMP(bag, BLDR.mp);
                        }else if (costume == "Karen")
                        {
                            user.hp = equHP(bag, JDG.hp);
                            user.str = equStr(bag, JDG.str);
                            user.luc = equLuc(bag, JDG.luc);
                            user.mp = equMP(bag, JDG.mp);
                        }else if (costume == "Discord Mod")
                        {
                            user.hp = equHP(bag, CB.hp);
                            user.str = equStr(bag, CB.str);
                            user.luc = equLuc(bag, CB.luc);
                            user.mp = equMP(bag, CB.mp);
                        }
                    }
                }
                
            break;// end of Choice 1
            case 2: //Choice 2 Check out folder
                cout<< "You go over to the folder on the floor by your laptop and open it to see it full of random TAROT cards:\n";
                for (size_t i = 0; i < 10; i++) // displays all items and their descriptons hence items [0] [i] and items [1] [i]
                {
                    cout<< i +1 << ':' << items [0] [i] << ": " << items[1] [i] << endl;
                }
                cout<< "Do you want to put some in your bag? 0:No 1:Yes\n";
                cin >> c2;
                while (c2 !=0)//another sentinal loop to be able to keep adding cards exit when c2=0
                {
                    for (size_t i = 0; i < 10; i++) // displays all items and their descriptons hence items [0] [i] and items [1] [i]
                    {
                        cout<< i +1 << ':' << items [0] [i] << ": " << items[1] [i] << endl;
                    }
                    cout << "Which card you like to add, you can take multiple of the same one if you'd like\n[0]:Put away folder [1-10]: Put card in bag\n";
                    cin >> c2;
                    if (c2 > 0 && c2 < 11 && bag[0] != "Death"&& bag[1] != "Death"&& bag[2] != "Death") //Checks to make sure that item number is in valid range and that death is not one of the current items in players bag
                    {
                        cout << items [1] [c2-1] << " Okay where would you like to put this (placement matters)[0/1/2/3]\n 0: To cancel\n";    
                        for (size_t i = 0; i < 3; i++)// displays bag to show player what is in the bag and give a choice of where to put it
                        {
                            cout << i+1 << ": " << bag[i] << endl;
                        }
                        cin >> c3;
                        if (c3 != 0)
                        {   
                            if ( (c2-1) < 9)// checks to see if the itme is death to be added
                            {
                                bag [c3-1] = items[0] [c2-1];
                            }else if ((c2-1) == 9) // if death is being added to players inventory then all other slots buts be empty
                            {
                                if (c3 == 1)
                                {
                                    bag [0] = items [0] [c2-1];
                                    bag [1] = "Empty";
                                    bag [2] = "Empty";
                                } else if (c3 == 2)
                                {
                                    bag [1] = items [0] [c2-1];
                                    bag [0] = "Empty";
                                    bag [2] = "Empty";
                                } else if (c3 == 3)
                                {
                                    bag [2] = items [0] [c2-1];
                                    bag [1] = "Empty";
                                    bag [0] = "Empty";
                                }
                                
                            }
                        }
                    }else if(bag[0] == "Death" || bag[1] == "Death"|| bag[2] == "Death")// if death is already in the players inventory it will not let them equip more cards
                    {
                        cout << "You try to equip the TAROT card but it burns when you touch it\n";
                    }
                }
                if (costume == "Pajamas") // checks players class to ensure the right stats are being modified
                {
                    user.hp = equHP(bag, Base.hp);
                    user.str = equStr(bag, Base.str);
                    user.luc = equLuc(bag, Base.luc);
                    user.mp = equMP(bag, Base.mp);
                }else if (costume == "Sheriff")
                {
                    user.hp = equHP(bag, BLDR.hp);
                    user.str = equStr(bag, BLDR.str);
                    user.luc = equLuc(bag, BLDR.luc);
                    user.mp = equMP(bag, BLDR.mp);
                }else if (costume == "Karen")
                {
                    user.hp = equHP(bag, JDG.hp);
                    user.str = equStr(bag, JDG.str);
                    user.luc = equLuc(bag, JDG.luc);
                    user.mp = equMP(bag, JDG.mp);
                }else if (costume == "Discord Mod")
                {
                    user.hp = equHP(bag, CB.hp);
                    user.str = equStr(bag, CB.str);
                    user.luc = equLuc(bag, CB.luc);
                    user.mp = equMP(bag, CB.mp);
                }
                
                
                
            break;//End of Choice 2
            case 3:// Start of Choice 3 Check out closet
                cout << "You go to your closest that blocks the window, and open your closet and see a bunch of costumes would you like to put one on? They are as follows:\n0:To Go Back\n1:A Sheriff \n2:Karen\n3:Discord Mod\n4:Take off Costume\n[0/1/2/3/4]:";
                cin >> c2;
                if (c2 > 0 && c2 < 5)// ensures that players choice is one of the available choices
                {
                    switch (c2)
                    {
                    case 1:// put on Sheriff costume and stat change
                        costume = "Sheriff";
                        user.hp =BLDR.hp;
                        user.luc =BLDR.luc;
                        user.str =BLDR.str;
                        user.mp =BLDR.mp;
                        user.hp = equHP(bag, BLDR.hp);
                        user.str = equStr(bag, BLDR.str);
                        user.luc = equLuc(bag, BLDR.luc);
                        user.mp = equMP(bag, BLDR.mp);
                        cout << "You put on the Sheriff costume and your stats changed:\n";
                        cout << "HP: " << user.hp << endl;
                        cout << "Luc: " << user.luc<< endl;
                        cout << "Str: " << user.str<< endl;
                        cout << "MP: " << user.mp<< endl;
                        break;
                    case 2:// put on Karen costume and stat change
                        costume = "Karen";
                        user.hp =JDG.hp;
                        user.luc =JDG.luc;
                        user.str =JDG.str;
                        user.mp =JDG.mp;
                        user.hp = equHP(bag, JDG.hp);
                        user.str = equStr(bag, JDG.str);
                        user.luc = equLuc(bag, JDG.luc);
                        user.mp = equMP(bag, JDG.mp);
                        cout << "You put on the Karen costume and your stats changed:\n";
                        cout << "HP: " << user.hp<< endl;
                        cout << "Luc: " << user.luc<< endl;
                        cout << "Str: " << user.str<< endl;
                        cout << "MP: " << user.mp<< endl;
                        break;
                    case 3: // put on Discord mod costume and stat change
                        costume = "Discord Mod";
                        user.hp =CB.hp;
                        user.luc =CB.luc;
                        user.str =CB.str;
                        user.mp =CB.mp;
                        user.hp = equHP(bag, CB.hp);
                        user.str = equStr(bag, CB.str);
                        user.luc = equLuc(bag, CB.luc);
                        user.mp = equMP(bag, CB.mp);
                        cout << "You put on the Discord costume and your stats changed:\n";
                        cout << "HP: " << user.hp<< endl;
                        cout << "Luc: " << user.luc<< endl;
                        cout << "Str: " << user.str<< endl;
                        cout << "MP: " << user.mp<< endl;
                        break;
                    case 4:// Take off costume results in pajamas, or base stats being applied
                        if (costume != "Pajamas")// checks to make sure that the costume is not Pajamas
                        {
                            costume = "Pajamas";
                            user.hp =Base.hp;
                            user.luc =Base.luc;
                            user.str =Base.str;
                            user.mp =Base.mp;
                            user.hp = equHP(bag, Base.hp);
                            user.str = equStr(bag, Base.str);
                            user.luc = equLuc(bag, Base.luc);
                            user.mp = equMP(bag, Base.mp);
                            cout << "You put your Pajamas back on and your stats changed:\n";
                            cout << "HP: " << user.hp<< endl;
                            cout << "Luc: " << user.luc<< endl;
                            cout << "Str: " << user.str<< endl;
                            cout << "MP: " << user.mp<< endl;
                        }else {
                            cout << "You can't take off your skin no matter how much hard you try\n";
                        }
                        break;
                    }
                }
                break;// End of Choice 3
            case 4:// Start of choice 4 Check out door, this code will most likely be the one to be changed when being passed off to another student there for nothing from this point on really matters 
                switch (door)
                {
                case 0:// first time opening door
                    cout << "You open the door and see a large void in the distance you see a window that says:\n'ERROR 404 OUTSIDE DOES NOT EXIST'\n You close the door\n";
                    break;
                case 1:// second time opening door
                    cout << "You open the door again and see a large void in the distance you see a window that says:\n'ERROR 404 OUTSIDE DOES NOT EXIST'\n You close the door\n";
                    break;
                case 2:// third time opening door
                    cout << "You know that theres nothing out there right? Open anyway?: 0:No 1:Yes\n";
                    cin >> c2;
                    if (c2 == 1)
                    {
                        cout << "You open the door again and see a large void in the distance you see a window that says:\n'ERROR 404 OUTSIDE DOES NOT EXIST'\n You close the door\n Really what did you expect, not like this game is done\n";
                    }else
                    {
                        cout << "Okay cool\n";
                    }
                    break;
                case 3:// fourth time opening door
                        cout << "You open the door and lean out with a look of desparation, there has to be more than this right?\nWithout hesitation you jump out into the seemingly endless void,\nWAIT WHAT ARE YOU DOING THERE IS NOTHING OUT THERE...(the narator's voice fades as you fall)\n[What would you like to do]: 1: Fall 2:Fall 3: Fall... [1-99999999999999999999999999]:\n";
                        cin >> c2;
                        for (size_t i = 0; i < 6; i++)
                        {
                            if (i == 5)
                            {
                                cout << "Would you like to reach out for help? 0:No 1:Yes\n";
                                cin >> c2;
                                if (c2 == 1)
                                {
                                    cout << "You reached out for help but no one is there. ";
                                }else
                                {
                                    cout << "You accepted that no one can help you. ";
                                }
                                cout << "You keep falling until everything \nis swallowed by the void and you can no longer see your room in the distance,\n You have fallen so far from where you started, How could this happen?";
                                return 0;// ends program
                            }else
                            {
                            cout << "You kept falling. [What would you like to do] undef:Fall [1-undef]\n ";
                            }
                            cin >> c2;
                        }
                }
                door++;// increases the value door which indicates a new instance when door is opened
            break;
        }
    }
}