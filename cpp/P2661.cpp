////
//// Created by Work on 2022/5/21.
////
//#include <bits/stdc++.height>
//using namespace std;
//int b, str[200005], color = 1, now;
//int role = 1;
//
//void deal(int temp1){
//    if(str[temp1 + 1] != now && role++ < 200005){
//        deal(str[temp1 + 1]);
//    }
//    color = min(color, role);
//    return;
//}
//int main(){
//    cin >> b;
//    for(int i = 1; i <= b; i++){
//        cin >> str[i];
//    }
//    for(int i = 1; i <= b; i++){
//        now = str[i];
//        deal(i);
//    }
//    cout << color << endl;
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 2100000000;
    for(int i = 1; i<=n; i++){
        int now = i, p = a[i];
        for(int j = 1; j <= 200005; j++){
            if(a[p] == now){
                ans = min(ans, j);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}