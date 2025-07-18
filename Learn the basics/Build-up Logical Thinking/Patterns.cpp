#include<bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/n-forest_6570177?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nForest(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << "* ";
		cout << "\n";
	}
}

// https://www.naukri.com/code360/problems/n-2-forest_6570178?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nForest(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++)
			cout << "* ";
		cout << "\n";
	}
}

// https://www.naukri.com/code360/problems/n-triangles_6573689?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nTriangle(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++)
			cout << j + 1 << " ";
		cout << "\n";
	}
}

// https://www.naukri.com/code360/problems/triangle_6573690?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=PROBLEM

void triangle(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++)
			cout << i + 1 << " ";
		cout << "\n";
	}
}

// https://www.naukri.com/code360/problems/seeding_6581892?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void seeding(int n) {
	for(int i = n; i >= 0; i--) {
		for(int j = i; j > 0; j--)
			cout << "* ";
		cout << '\n';
	}
}

// https://www.naukri.com/code360/problems/reverse-number-triangle_6581889?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems

void nNumberTriangle(int n) {
    for(int i = n; i >= 0; i--) {
        for(int j = 1; j <= i; j++)
            cout << j << " ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/star-triangle_6573671?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nStarTriangle(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++)
            cout << " ";
        for(int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/reverse-star-triangle_6573685?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nStarTriangle(int n) {
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n - i - 1; j++)
            cout << " ";
        for(int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/star-diamond_6573686?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nStarDiamond(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++)
            cout << " ";
        for(int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << "\n";
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n - i - 1; j++)
            cout << " ";
        for(int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/rotated-triangle_6573688?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nStarTriangle(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++)
            cout << "*";
        cout << "\n";
    }
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++)
            cout << "*";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/binary-number-triangle_6581890?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nBinaryTriangle(int n) {
    for(int i = 0; i < n; i++) {
        bool curr = !(i & 1);
        for(int j = 0; j < i + 1; j++) {
            cout << curr << " ";
            curr = !curr;
        }
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/number-crown_6581894?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void numberCrown(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++)
            cout << j + 1 << " ";
        for(int j = 0; j < 2 * (n - i - 1); j++)
            cout << " ";
        for(int j = i; j >= 0; j--)
            cout << j + 1 << " ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/increasing-number-triangle_6581893?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nNumberTriangle(int n) {
    int curr = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++)
            cout << curr++ << " ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/increasing-letter-triangle_6581897?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void nLetterTriangle(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++)
            cout << (char)(j + 'A') << " ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/reverse-letter-triangle_6581906?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=PROBLEM

void nLetterTriangle(int n) {
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < i; j++)
            cout << (char)('A' + j) << " ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/alpha-ramp_6581888?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void alphaRamp(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++)
            cout << (char)('A' + i) << " ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/alpha-hill_6581921?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void alphaHill(int n) {
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < 2 * i; j++)
            cout << " ";
        for(int j = 0; j < n - i; j++)
            cout << (char)('A' + j) << " ";
        for(int j = n - i - 2; j >= 0; j--)
            cout << (char)('A' + j) << " ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/alpha-triangle_6581429?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void alphaTriangle(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= n - i - 1; j--)
            cout << (char)('A' + j) << " ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/symmetric-void_6581919?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void symmetry(int n) {
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < i; j++)
            cout << "* ";
        for(int j = 0; j < n - i; j++)
            cout << "    ";
        for(int j = 0; j < i; j++)
            cout << "* ";
        cout << "\n";
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++)
            cout << "* ";
        for(int j = 0; j < n - i; j++)
            cout << "    ";
        for(int j = 0; j < i; j++)
            cout << "* ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/symmetry_6581914?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void symmetry(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++)
            cout << "* ";
        for(int j = 0; j < n - i - 1; j++)
            cout << "    ";
        for(int j = 0; j <= i; j++)
            cout << "* ";
        cout << "\n";
    }
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++)
            cout << "* ";
        for(int j = 0; j < n - i - 1; j++)
            cout << "    ";
        for(int j = 0; j <= i; j++)
            cout << "* ";
        cout << "\n";
    }
}

// https://www.naukri.com/code360/problems/ninja-and-the-star-pattern-i_6581920?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void getStarPattern(int n) {
    if(n == 1) {
        cout << "*";
        return;
    }
    for(int i = 0; i < n; i++)
        cout << "*";
    cout << "\n";
    for(int i = 0; i < n - 2; i++) {
        cout << "*";
        for(int j = 0; j < n - 2; j++)
            cout << " ";
        cout << "*";
        cout << "\n";
    }
    for(int i = 0; i < n; i++)
        cout << "*";
}

// https://www.naukri.com/code360/problems/ninja-and-the-number-pattern-i_6581959?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&leftPanelTabValue=SUBMISSION

void getNumberPattern(int n) {
    for(int i = 0; i < n; i++) {
        int num = n;
        for(int j = 0; j < i + 1; j++)
            cout << num--;
        num++;
        for(int j = 0; j < 2 * (n - i - 1) - 1; j++)
            cout << num;
        for(int j = 0; j < i + 1; j++) {
            if(num == 1) {
                num++;
                continue;
            }
            cout << num++;
        }
        cout << "\n";
    }
    for(int i = n - 2; i >= 0; i--) {
        int num = n;
        for(int j = 0; j < i + 1; j++)
            cout << num--;
        num++;
        for(int j = 0; j < 2 * (n - i - 1) - 1; j++)
            cout << num;
        for(int j = 0; j < i + 1; j++) {
            if(num == 1)
                continue;
            cout << num++;
        }
        cout << "\n";
    }
}