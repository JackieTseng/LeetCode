/*********************************************************************************
 * Leetcode : Rectangle Area -- https://leetcode.com/problems/rectangle-area/
 * Coded in Seq 2nd, 2015
 *
 * [Problem]
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * 
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 * 
 * Assume that the total area is never beyond the maximum possible value of int.
 *********************************************************************************/
#include <algorithm>
#include <iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area = (C - A) * (D - B) + (G - E) * (H - F);
    if (A >= G || E >= C || B >= H || F >= D) {
        return area;
    }
    //return area - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
    return area - ((C < G ? C : G) - (A > E ? A : E)) * ((D < H ? D : H) - (B > F? B : F));
}

int main(int argc, const char *argv[]) {
    return 0;
}
