#include <stdio.h>
#include <stdbool.h>

int logs[100];

bool break_day[100], not_break_day[100];

int main() {
    int n;
    scanf("%d\n", &n);
    
    for(int i=0; i<n; ++i) {
        scanf("%d", &logs[i]);
    }

    int minimum = 0, maximum = 0;
    int last_break = 0; // 0일째 break
    break_day[0] = true;

    for(int i=0; i<n; ++i) {
        if (logs[i] != -1) {
            if (i - last_break < logs[i] || not_break_day[i - logs[i]]) {
                printf("%d\n", -1);
                return 0;
            }
            else {
                break_day[i - logs[i]] = true;
                
                last_break = i - logs[i];

                for(int j=last_break + 1; j <= i; ++j) {
                    not_break_day[j] = true;
                }
            }
        }
    }
    
    for(int i=0; i<n; ++i) {
        
        if (break_day[i] == true) {
            minimum++;
        }
        if (!not_break_day[i]) {
            maximum++;
        }
    }

    printf("%d %d\n", minimum, maximum);

    return 0;
}