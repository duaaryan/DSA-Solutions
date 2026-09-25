#include <vector>
#include <algorithm>

using namespace std;

struct Box {
    int h, w, l;
};

// ❌ Potential Buggy Comparator
bool compareBoxes(Box a, Box b) {
    return (1LL * a.w * a.l) > (1LL * b.w * b.l);
}




class Solution {
public:
    int maxHeight(vector<int>& height, vector<int>& width, vector<int>& length) {
        int n = height.size();
        vector<Box> boxes;

        // 1. Generate all 3 rotations for each box
        for (int i = 0; i < n; i++) {
            // Rotation 1: height[i] is the height
            boxes.push_back({height[i], min(width[i], length[i]), max(width[i], length[i])});

            // Rotation 2: width[i] is the height
            boxes.push_back({width[i], min(height[i], length[i]), max(height[i], length[i])});

            // Rotation 3: length[i] is the height
            boxes.push_back({length[i], min(height[i], width[i]), max(height[i], width[i])});
        }

        // 2. Sort boxes in descending order of base area
        sort(boxes.begin(), boxes.end(), compareBoxes);

        int numBoxes = boxes.size();
        vector<int> msh(numBoxes);

        // Initialize maximum stack height for each box with its own height
        for (int i = 0; i < numBoxes; i++) {
            msh[i] = boxes[i].h;
        }

        int maxTotalHeight = 0;

        // 3. Perform LIS-like dynamic programming
        for (int i = 0; i < numBoxes; i++) {
            for (int j = 0; j < i; j++) {
                // Check if box i can be placed strictly on top of box j
                if (boxes[i].w < boxes[j].w && boxes[i].l < boxes[j].l) {
                    if (msh[i] < msh[j] + boxes[i].h) {
                        msh[i] = msh[j] + boxes[i].h;
                    }
                }
            }
            maxTotalHeight = max(maxTotalHeight, msh[i]);
        }

        return maxTotalHeight;
    }
};
