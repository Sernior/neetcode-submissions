class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        std::vector<std::pair<int, int>> posSpeed;

        posSpeed.reserve(position.size());

        for (int i = 0; i < position.size(); ++i)posSpeed.emplace_back(position[i], speed[i]);

        std::sort(posSpeed.begin(), posSpeed.end());

        std::reverse(posSpeed.begin(), posSpeed.end());

        double nextReachableFleetTime = 0;

        int fleetNumber = 0;

        for (auto const& ps : posSpeed){
            double timeOfArrival = static_cast<double>(target - ps.first) / static_cast<double>(ps.second);
            if (timeOfArrival > nextReachableFleetTime){
                ++fleetNumber;
                nextReachableFleetTime = timeOfArrival;
            }
        }

        return fleetNumber;
    }
};
