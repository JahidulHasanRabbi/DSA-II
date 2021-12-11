#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n, totalCapacity;
    cin >> totalCapacity;
    cin >> n;

    int w[n];
    int v[n];

    for(int i=0; i<n; i++) {
        cin >> w[i] >> v[i];
        cout << w[i] << " w " << v[i] << " v " << endl;
    }

    sort(v, v+n-1);

    int totalWeight = 0;
    int finalValue = 0;
    int restOfFriciton = 0;

    for(int i=0; i<n; i++) {
        if(totalWeight + w[i] <= totalCapacity) {
           finalValue += v[i];
           totalCapacity += w[i];
        }
        else {
            int restOfFriciton = totalCapacity - totalWeight;
            finalValue += v[i] * (restOfFriciton / w[i]);
            break;
        }
    }

    cout << "Total Value : " << finalValue << endl;

    return 0;
}