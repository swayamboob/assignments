#include <bits/stdc++.h>
using namespace std;
class Memory
{
public:
    void First_Fit(int A[], int m, int B[], int n)
    {
        int Temp[n];
        // Initially no block is assigned to any process
        memset(Temp, -1, sizeof(Temp));
        // pick each process and find suitable blocks
        // according to its size ad assign to it
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (A[j] >= B[i])
                {
                    Temp[i] = j;
                    A[j] -= B[i];
                    break;
                }
            }
        }
        cout << "Process No.\t\tProcess Size\t\tBlock no." << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "\t" << i + 1 << "\t\t\t";
            cout << B[i] << "\t\t\t";
            if (Temp[i] != -1)
            {
                cout << Temp[i] + 1 << endl;
            }
            else
            {
                cout << "Not Allocated!" << endl;
            }
        }
    }
    void Best_Fit(int A[], int m, int B[], int n)
    {
        int Temp[n];
        // Initially no block is assigned to any process
        memset(Temp, -1, sizeof(Temp));
        // pick each process and find suitable blocks
        // according to its size ad assign to it
        for (int i = 0; i < n; i++)
        {
            int demo = -1;
            for (int j = 0; j < m; j++)
            {

                if (A[j] >= B[i])
                {
                    if (demo == -1)
                    {
                        demo = j;
                    }
                    else if (A[j] < A[demo])
                    {
                        demo = j;
                    }
                }
            }
            if (demo != -1)
            {
                // allocate block j to p[i] process
                Temp[i] = demo;

                // Reduce available memory in this block.
                A[demo] -= B[i];
            }
        }
        cout << "Process No.\t\tProcess Size\t\tBlock no." << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "\t" << i + 1 << "\t\t\t";
            cout << B[i] << "\t\t\t";
            if (Temp[i] != -1)
            {
                cout << Temp[i] + 1 << endl;
            }
            else
            {
                cout << "Not Allocated!" << endl;
            }
        }
    }
    void Worst_Fit(int A[], int m, int B[], int n)
    {
        int Temp[n];
        // Initially no block is assigned to any process
        memset(Temp, -1, sizeof(Temp));
        // pick each process and find suitable blocks
        // according to its size ad assign to it
        for (int i = 0; i < n; i++)
        {
            int demo = -1;
            for (int j = 0; j < m; j++)
            {

                if (A[j] >= B[i])
                {
                    if (demo == -1)
                    {
                        demo = j;
                    }
                    else if (A[j] > A[demo])
                    {
                        demo = j;
                    }
                }
            }
            if (demo != -1)
            {
                // allocate block j to p[i] process
                Temp[i] = demo;

                // Reduce available memory in this block.
                A[demo] -= B[i];
            }
        }
        cout << "Process No.\t\tProcess Size\t\tBlock no." << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "\t" << i + 1 << "\t\t\t";
            cout << B[i] << "\t\t\t";
            if (Temp[i] != -1)
            {
                cout << Temp[i] + 1 << endl;
            }
            else
            {
                cout << "Not Allocated!" << endl;
            }
        }
    }
    void Next_Fit(int A[], int m, int B[], int n)
    {
        int Temp[n];
        // Initially no block is assigned to any process
        memset(Temp, -1, sizeof(Temp));
        // pick each process and find suitable blocks
        // according to its size ad assign to it
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            // Do not start from beginning
            while (j < m)
            {
                if (A[j] >= B[i])
                {
                    // allocate block j to p[i] process
                    Temp[i] = j;
                    // Reduce available memory in this block.
                    A[j] -= B[i];

                    break;
                }

                // mod m will help in traversing the blocks from
                // starting block after we reach the end.
                j = (j + 1) % m;
            }
        }
        cout << "\nProcess No.\tProcess Size\tBlock no.\n";
        for (int i = 0; i < n; i++)
        {
            cout << " " << i + 1 << "\t\t" << B[i]
                 << "\t\t";
            if (Temp[i] != -1)
                cout << Temp[i] + 1;
            else
                cout << "Not Allocated";
            cout << endl;
        }
    }
};

int main()
{
    Memory m1;
    int m, n;
    cout << "\nEnter the Block Size - ";
    cin >> m;
    cout << "\nEnter the Process Size - ";
    cin >> n;
    int block_size[m], process_size[m];
    cout << "\nEnter the Values in Block Size - " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> block_size[i];
    }
    cout << "\nEnter the Values in Process Size - " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> process_size[i];
    }
    cout << endl
         << endl;
    // Next_Fit(block_size, m, process_size, n);
    int ch;
    do
    {
        cout << "\n1.First Fit Memory placement strategies - " << endl;
        cout << "\n2.Best Fit Memory placement strategies - " << endl;
        cout << "\n3.Worst Fit Memory placement strategies - " << endl;
        cout << "\n4.Next Fit Memory placement strategies - " << endl;
        cout << "\nEnter the Choice - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            m1.First_Fit(block_size, m, process_size, n);
            break;
        case 2:
            m1.Best_Fit(block_size, m, process_size, n);
            break;
        case 3:
            m1.Worst_Fit(block_size, m, process_size, n);
            break;
        case 4:
            m1.Next_Fit(block_size, m, process_size, n);
            break;
        case 5:
            m1.First_Fit(block_size, m, process_size, n);
            m1.Best_Fit(block_size, m, process_size, n);
            m1.Worst_Fit(block_size, m, process_size, n);
            break;
        default:
            break;
        }
    } while (ch != -1);

    return 0;
}

/*
Input : blockSize[]   = {100, 500, 200, 300, 600};
        processSize[] = {212, 417, 112, 426};
Output:
Process No.    Process Size    Block no.
   1               212            2
   2               417            5
   3               112            3
   4               426        Not Allocated

*/