
//
//  0620.cpp
//  Study
//
//  Created by 경현 on 2017. 6. 20..
//  Copyright © 2017년 박경현. All rights reserved.
//


#include <iostream>

using namespace std;

// DP를 쓰기 전에,,,재귀로 한번 구해보자

int findStairsScore(int curStep, int count, int maxScore);


int result[300][2]; // result[i][0] -> max , result[i][1] -> count
int stairCount; // 계단의 개수.
int step[300]; // 계단의 점수.


int main(int argc, const char * argv[]) {
    
    //    fill_n(result, 300, -1);
    
    cin>>stairCount;
    step[0] = 0;
    
    for(int i = 1 ; i<=stairCount; i++){ // 시작점 0부터 ~ 계단의 개수까지.
        cin >> step[i];
    }
    
    /*
     * 첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최대값을 출력한다.
     * 1. result 안에는 해당 계단까지의 최대점수를 저장한다.
     * 2. 이전의 계단에서 몇칸올라왔는지....
     * 그럼...결과적으로 2차원 배열이 필요함
     *
     */
    
    result[0][0] = 0; // 시작점의 max = 0
    result[0][1] = 0; // 시작점의 count = 0
    
    
    
    
    int result = findStairsScore(0,0,0); // 첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최대값을 출력한다.
    cout << result << endl;
    
    return 0;
}

int findStairsScore(int curStep, int count, int maxScore){
    
    
    if(count == 3){ // 이는 허용할 수 없다.
        return maxScore;
    }
    
    
    if(curStep > stairCount) // +2를 하면 넘어가는 경우가 생긴다...
        return maxScore;
    
    maxScore += step[curStep];
    
    if(curStep == stairCount) // +2를 하면 넘어가는 경우가 생긴다...
        return maxScore;
    
    
    
    
    // 첫번째 계단부터 시작....1칸이동
    int result_a = findStairsScore(curStep+1, count+1, maxScore);
    
    // 만약 count = 3이면...이는 안되는데..... 함수 도입할때 체크.
    
    // 두번째 계단부터 시작....2칸이동
    int result_b = findStairsScore(curStep+2, 1, maxScore);
    
    if(result_a > result_b)
        maxScore = result_a;
    else
        maxScore = result_b;
    
    
    return maxScore;
}





