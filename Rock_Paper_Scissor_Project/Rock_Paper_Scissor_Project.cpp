// resolotion project one 222.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;
enum enchoice { Rock = 1, scissor = 2, paper = 3 };
enum enwinner { computer = 1, user = 2, Tie = 3 };
struct stroundinfo
{
    int Round_Number;
    enchoice computerchoice;
    enchoice Playerchoice;
    string roundwinner = "";

};
struct stGameinfo
{
    int userwins = 0;
    int computerwins = 0;
    int Drowtimes = 0;
    int Round_NUMBER = 0;

    string finalwinner = "";

};
int Read_Number(string message, int From, int To)
{
    int number = 0;
    while (number < From || number > To)
    {
        cout << message << endl;
        cin >> number;
    }
    return number;
}
int Random(int From, int To)
{
    int number = rand() % (To - From + 1) + From;
    return number;
}
stroundinfo Round_rules(stroundinfo info)
{
    if (info.Playerchoice == scissor && info.computerchoice == Rock)
    {
        info.roundwinner = "Computer";
        system("color 4F");
    }
    else if (info.computerchoice == scissor && info.Playerchoice == paper)
    {
        info.roundwinner = "Computer";
        system("color 4F");
    }
    else if (info.computerchoice == paper && info.Playerchoice == Rock)
    {
        info.roundwinner = "Computer";
        system("color 4F");
    }
    else if (info.Playerchoice == Rock && info.computerchoice == scissor)
    {
        info.roundwinner = "user";
        system("color 2F");

    }
    else if (info.Playerchoice == scissor && info.computerchoice == paper)
    {
        info.roundwinner = "user";
        system("color 2F");

    }
    else if (info.Playerchoice == paper && info.computerchoice == Rock)
    {
        info.roundwinner = "user";
        system("color 2F");

    }
    else
    {
        info.roundwinner = "Drow";
        system("color 6F");
    }
    return info;

}
string parser(enchoice  choice)
{
    switch (choice)
    {
    case Rock:
        return "Rock";
        break;
    case scissor:
        return "scissor";
        break;
    case paper:
        return "paper";
        break;
    default:
        break;
    }
}
void Roundstructuer(stroundinfo info)
{
    cout << "=========================================================================\n";
    cout << " user choice     :" << parser(info.Playerchoice) << endl;
    cout << " Computer choice :" << parser(info.computerchoice) << endl;
    cout << " Winner :" << info.roundwinner << endl;
    cout << "=========================================================================\n";
}
enchoice Computerchoice()
{
    return (enchoice)Random(1, 3);
}
void Get_Roundinfo(stroundinfo& info)
{
    info.Playerchoice = (enchoice)Read_Number("Rock [1] , scissor [2] , paper[3] ?", 1, 3);
    //info.computerchoice = (enchoice)Read_Number("Rock [1] , scissor [2] , paper[3] ?", 1, 3);
    info.computerchoice = Computerchoice();
    info = Round_rules(info);
    Roundstructuer(info);

}

stGameinfo FinalGame_Rules(stGameinfo& Finalinfo, stroundinfo info)
{
    if (info.Playerchoice == scissor && info.computerchoice == Rock)
    {
        Finalinfo.computerwins++;
    }
    else if (info.computerchoice == scissor && info.Playerchoice == paper)
    {
        Finalinfo.computerwins++;
    }
    else if (info.computerchoice == paper && info.Playerchoice == Rock)
    {
        Finalinfo.computerwins++;
    }
    else if (info.Playerchoice == Rock && info.computerchoice == scissor)
    {
        Finalinfo.userwins++;

    }
    else if (info.Playerchoice == scissor && info.computerchoice == paper)
    {
        Finalinfo.userwins++;


    }
    else if (info.Playerchoice == paper && info.computerchoice == Rock)
    {
        Finalinfo.userwins++;


    }
    else
    {
        Finalinfo.Drowtimes++;
    }
    return Finalinfo;

}

void FinalGame_Result(stGameinfo finalinfo)
{
    cout << "==================================================================================\n";
    cout << " ======================== <<<GAME OVER >>>==========================================\n";
    cout << "\tNUMBER OF ROUNDS :" << finalinfo.Round_NUMBER << endl;
    cout << "\tCOMPUTER WIN/s  :" << finalinfo.computerwins << endl;
    cout << "\tUSER WIN/s       :" << finalinfo.userwins << endl;
    cout << "\tDROW TIME/s      :" << finalinfo.Drowtimes << endl;
    if (finalinfo.computerwins > finalinfo.userwins)
    {
        finalinfo.finalwinner = "COMPUTER";
        cout << "\tFINAL WINNER  :" << finalinfo.finalwinner << endl;
    }
    else if (finalinfo.computerwins < finalinfo.userwins)
    {

        finalinfo.finalwinner = "USER";
        cout << "\tFINAL WINNER :" << finalinfo.finalwinner << endl;
    }
    else
    {
        finalinfo.finalwinner = "TIE THERE IS NO WINNER";
        cout << "\tFINAL WINNER :" << finalinfo.finalwinner << endl;
    }


}

int main()
{
    srand((unsigned)time(NULL));
    stroundinfo info;
    stGameinfo Finalinfo;
    char x;
    do
    {


        int round_number = Read_Number("Plz Enter How May Rounds Do You Want To Play From 1 To 10\n", 1, 10);
        Finalinfo.Round_NUMBER = round_number;
       for(int i = 1 ; i<= round_number;i++)
        {
            cout << "\n==================== ROUND  " << i   << "  BEGINS =================================\n";
            Get_Roundinfo(info);
            FinalGame_Rules(Finalinfo, info);
        }
        FinalGame_Result(Finalinfo);
        cout << "========================== DO YOU WANT TO PLAY AGAIN YES[y], NO[n]";
        cin >> x;
    } while (toupper(x));
    
    //sdfsdfsf

}