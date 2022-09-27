#include <iostream>

using namespace std;

// Реалізувати  алгоритм  для  розв’язання  задачі  «Ханойські  вежі».
// Виписати послідовність ходів для перекладання n дисків вежі (n = 2;
// 3; 4; 5 дисків).

// https://www.youtube.com/watch?v=YstLjLCGmgg
// https://www.mathsisfun.com/games/towerofhanoi.html

void hanoi(int desks_stack, int from_rod, int to_rod, int aux_rod)
{
    if(desks_stack==1)
    {
        cout<<"Move disk 1 from rod "<<from_rod<<" to rod "<<to_rod<<endl;
        return ;
    }
    hanoi(desks_stack-1, from_rod, aux_rod, to_rod);
    cout<<"Move disk "<<desks_stack<<" from rod "<<from_rod<<" to rod "<<to_rod<<endl;
    hanoi(desks_stack-1,  aux_rod,to_rod,from_rod);
}

int main()
{
    hanoi(5, 1, 3, 2);

    return 0;
}
