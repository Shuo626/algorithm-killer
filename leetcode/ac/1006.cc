#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int curN;
    int curOp;

    enum Operation {
        NONE = -1,
        MUL,
        DIV,
        ADD,
        SUB
    };

    int clumsy(int N) {
        curN = N;
        curOp = 0;

        return expression();
    }

    int expression() {
        int var1, var2;
        
        var1 = item();

        while (curN > 0) {
            int op;

            op = getOp();
            var2 = item();

            if (op == ADD) {
                var1 = var1 + var2;
            } else {
                var1 = var1 - var2;
            }
        }

        return var1;
    }

    int item() {
        int var1, var2;

        var1 = factor();

        if (nextOpIs(DIV)) {
            int op;

            op = getOp();
            var2 = factor();
            var1 = var1 / var2;
        }

        return var1;
    }

    int factor() {
        int var1, var2;

        var1 = getN();

        if (nextOpIs(MUL)) {
            int op;

            op = getOp();
            var2 = factor();
            var1 = var1 * var2;
        }

        return var1;
    }

    int getN() {
        int n;
        n = curN;
        curN -= 1;

        return n;
    }

    int getOp() {
        if (curN == 0) {
            return NONE;
        }

        int op;

        op = curOp % 4;
        curOp += 1;

        return op;
    }

    bool nextOpIs(Operation op) {
        return ((curN != 0) && (curOp % 4) == op);
    }
};


int main() {
    int ans;

    Solution solution;

    ans = solution.clumsy(10);

    cout << ans << endl;
}