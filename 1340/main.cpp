#include <iostream>
#include <algorithm>

using namespace std;

struct OBIECTE 
{
    int val,greutate;
    double med;
}v[1000];

bool cmp(OBIECTE a,OBIECTE b)
{
    if (a.med < b.med)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int i,n,gmax,greu = 0,conto;
    double valo = 0;
    
    cin >> n >> gmax;
    for (i = 1;i <= n;i++)
    {
        cin >> v[i].greutate >> v[i].val;
        v[i].med = (double) v[i].val / (double) v[i].greutate;
    }
    sort(v + 1,v + n + 1,cmp);
    for (i = 1;i <= n;i++)
    {
        if (greu == gmax)
        {
            break;
        }
        else
        {
            conto = gmax - greu;
            if (conto >= v[i].greutate)
            {
                valo = valo + (double) v[i].val;
                greu = greu + v[i].greutate;
            }
            else
            {
                valo = valo + (double) conto * v[i].med;
                greu = greu + conto;
            }
        }
    }
    cout << valo;
    
    return 0;
}