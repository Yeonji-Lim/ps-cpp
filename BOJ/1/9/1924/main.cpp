#include <cstdio>

// 아래 주석 처리된 코드 뭐가 틀린건지 찾아보자.. 찾았지만 다음에 보면 또 모를 가능성 있음
//int main() {
//    int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
//    char *dayOfWeek[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
//    int month, day;
//    scanf("%d %d", &month, &day);
//    for(int i = 1; i < month; ++i) {
//        day += daysOfMonth[i];
//    }
//    printf("%s\n", dayOfWeek[day % 7]);
//    return 0;
//}

int main() {
    int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *dayOfWeek[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month, day;
    scanf("%d %d", &month, &day);
    for(int i = 1; i < month; ++i) {
        day += daysOfMonth[i];
    }
    printf("%s\n", dayOfWeek[day % 7]);
    return 0;
}
