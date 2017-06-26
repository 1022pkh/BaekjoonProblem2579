//
//  0620.cpp
//  Study
//
//  Created by 경현 on 2017. 6. 20..
//  Copyright © 2017년 박경현. All rights reserved.
//


#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    
    int result[305][2] = { 0, };
    int stairCount; // 계단의 개수.
    int step[305] = { 0, };
    
    cin>>stairCount;
    
    for(int i = 1 ; i<=stairCount; i++){ // 시작점 0부터 ~ 계단의 개수까지.
        cin >> step[i];
    }
    
    /**
     Nx2배열을 만든 후에 
     D[N,0]은 이전단계까지 더해온 값에 현재 계단 값을 더한 값이고,
     D[N,1]은 2계단 전까지 왔던 값에 현재값을 더한 값이다. 즉, 그 두 값 중 max값을 계속 갱신해가면 마지막엔 최대값이 담겨있게 된다.
     
     */
    
    result[1][1] = step[1];
    
    for (int i = 2; i <= stairCount; i++) {
        result[i][0] = result[i-1][1] + step[i];
        result[i][1] = max(result[i-2][0], result[i-2][1]) + step[i];
    }
    
    
    cout << max(result[stairCount][0],result[stairCount][1]) << endl;
    
    
    return 0;
}
