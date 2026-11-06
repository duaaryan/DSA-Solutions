class Solution {
public:
    vector<string> generateUsernames(vector<string>& arr) {
        vector<string> result;

        // 1. Pre-populate registered set with all original requested names
        unordered_set<string> registered(arr.begin(), arr.end());

        // Tracks names we have already processed/encountered
        unordered_set<string> seen; 
        unordered_map<string, int> nextSuffix; 

        for (const string& name : arr) {
            // Case 1: First time seeing this specific request
            if (seen.find(name) == seen.end()) {
                result.push_back(name);
                seen.insert(name);
            }
            // Case 2: This base username has been requested before
            else {
                int suffix = nextSuffix[name] > 0 ? nextSuffix[name] : 1;
                string newName = name + to_string(suffix);

                // Find the next available suffix that doesn't clash with any 
                // original name or previously generated name
                while (registered.find(newName) != registered.end()) {
                    suffix++;
                    newName = name + to_string(suffix);
                }

                result.push_back(newName);
                registered.insert(newName); // Reserve this generated name
                nextSuffix[name] = suffix + 1; // Save progress for the next time
            }
        }

        return result;
    }
};

