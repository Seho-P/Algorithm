#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int smin = 10000;
	int omin = 10000;
	for (int i = 0; i < M; i++) {
		int s, o;
		cin >> s >> o;

		smin = min(smin, s);
		omin = min(omin, o);
	}
	int temp,temp2;
    if(N%6==0){
        temp = smin * (N/6);
        temp2 = omin * (N);
    }
    else{
        temp = min(smin * (N/6 + 1),smin * (N/6) + omin*(N%6));
        temp2 = omin * (N);
    }
    
	cout << min(temp, temp2);

	return 0;
}