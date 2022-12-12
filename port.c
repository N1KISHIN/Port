#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

struct xorshift32_state {
    uint32_t a;
};

uint32_t xorshift32(struct xorshift32_state *state) {
    uint32_t x = state->a;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return state->a = x;
}
int last_max = 0;
struct xorshift32_state *global_state = NULL;

float rnd(int max) {
    if (global_state == NULL) {
        global_state = malloc(sizeof(struct xorshift32_state));
    }
    if (max == 0) {
        float value = global_state->a / (float)UINT32_MAX;
        return last_max*value;
    }
    last_max = max;
    global_state->a = xorshift32(global_state);
    float value = global_state->a / (float)UINT32_MAX;
    return value*max;
}



int main(){
    int l;
    int w;
    float g;
    float t;
    printf("CUP");
    printf("MIREA PROJECT");
    printf("RUSSIA, MOSCOW");
    printf("\n");
    int s[30][60];
n30:
    l = 27;//(int)(60 * rnd(1)) + 1;
    printf("l = %f\n",l);
    if (l == 60 || l == 1) goto n30;
    g = 4;//(int)(10 * rnd(1)) + 1;
    printf("g = %f\n",g);
n60:
    printf("THE CUP IS 30 LINES DOWN AND %i", l);
    printf(" SPACES OVER. \n");
    printf("THE PULL OF GRAVITY IS %i", g);
    printf(" LINES/SECOND/SECDND \n");
    printf("WHAT IS THE PUSH YOU WOULD LIKE TO GIVE THE BALL\n");
    printf(" ACROSS THE PAPER (IN SPACES/SECOND)\n");
    scanf("%f", &t);
    printf("THE RESULTS MAY TAKE ANYWHERE BETWEEN 30 AND 90 SECONDS.\n");
    printf("g = %i\n", g);
    for (int s1 = 0; s1 < 30; s1++){
        for (int s2 = 0; s2 < 60; s2++){
            s[s1][s2] = 0;
        }
    }
    float count = ((60 * g) * (60 * g)) / g;
    for (float z = 1; z <= count; z += 0.01){
        float y = (t*z*2);
        float x = (g/2*z*z);
        if (x > 30.5 || x < 0.5 || y > 60.5 || y <0.5) goto n300;
        if ((int)x == 29 && (int)y == l) goto n310;
        if ((int)(x+1) == 29 && (int)y+1 == l) goto n310;
        if ((int)x+1 == 29 && (int)y+1 ==l) goto n310;
        if ((int)x == 29 && (int)y == l-1) goto n310;
        if ((int)x+1 == 29 && (int)y+1 == l-1) goto n310;
        if ((int)x == 29 && (int)y == l+1) goto n330;
        if ((int)x+1 == 29 && (int)y+1 == l+1) goto n330;
        s[(int)x-1][(int)y-1] = 2;
        for (int d = 1; d <=5; d+= 1){
            if ((int)y < 6) goto n290;
            s[(int)x-1][(int)y-d-1] = 0;
        };    
n290:
    }
n300: 
    goto n340;
n310:
    w = 1;
    goto n335;
n330:
    w = 2;
n335:
    s[28][(int)l] = 2;
    goto n345;
n340:
    w = 0;   
n345:
    s[29][(int)l] = 1;
    s[29][(int)l-1] = 1;
    s[29][(int)l+1] = 1;
    s[28][(int)l-1] = 1;
    s[28][(int)l+1] = 1;
    for (int x = 0; x < 30; x++){
        for (int x1 = 0; x1 < 60; x1++){
            if (s[x][x1] != 0) goto n420;
        }
        goto n500;
n420:
        for (int y = 0; y < 60; y++){
            if (s[x][y] == 0){
                printf(" ");
            }
            if (s[x][y] == 1){
                printf("*");
            }
            if (s[x][y] == 2){
                printf(".");
            }
            if ((x == 28 || x == 29)) continue;
            if (y == 59 || y == 0) continue;
            if (y == 0 || y == 58) break;
            if (s[x][y] == 2 && s[x][y+1] == 0) break;
            if (s[x][y] == 1 && s[x][y+1] == 0 && s[x][y+2] == 0) break;
        }       
n500:
    printf("\n");
    }
    printf("\n");
    if (w == 1) goto n570;
    if (w == 2) goto n590;
    printf("YOU MISSED; TRY AGAIN.");
    goto n60;
n570:
    printf("RIGHT IN!!!");
n590:
    printf("YOU ALMOST DIDN'T MAKE IT, BUT IT BOUNCED IN.");
}