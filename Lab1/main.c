#include<stdio.h>


void towerOfHanoi(int ,char,char, char);
int gcd(int , int );


void main()
{
    int ch;
    while(1){
    printf("\n\n Enter option:> \n 1. Tower of Hanoi \n 2. Gcd of two numbers  \n 3. Exit \n \t :>  ");
    scanf("%d",&ch);
        if(ch==1)
        {
        printf("\n <-----Tower OF Hanoi--->\n ");
        int  n;
        printf("\n \t enter the number of disks..\t ");
        scanf("%d",&n);
        towerOfHanoi(n,'A','C','B');
        }

        else if(ch==2)
        {
            printf("\n <-----GCD of two numbers--->\n ");
            int num1, num2;
            printf("Enter two positive integers: \n");
            scanf("  %d   %d", &num1, &num2);
            printf("G.C.D of %d and %d is %d.", num1, num2, gcd(num1, num2));

        }
        else if(ch==3)
        {

            exit(0);
        }
        else
        {
            printf("invalid option selected!!");
        }
        printf("\n \n \t ---------------------------\n ");
    }
}



        void towerOfHanoi(int n, char from_rod,char to_rod, char aux_rod)
        {
            if (n == 1)
            {
                printf( "Move disk 1 from rod %c  to rod  %c \n" ,from_rod, to_rod);
                return;
            }
            towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
            printf( "Move disk %d from rod %c  to rod  %c \n", n,from_rod, to_rod );
            towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
        }


            int gcd(int n1, int n2) {
                if (n2 != 0)
                    return gcd(n2, n1 % n2);
                else
                    return n1;
            }
