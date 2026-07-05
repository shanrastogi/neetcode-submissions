class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        std::vector<std::pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }

        std::sort(cars.begin(), cars.end(),
                  [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                      return a.first > b.first;
                  });

        int fleet = 0;
        double lastTime = 0.0;

        for (int i = 0; i < n; ++i) {
            double time = static_cast<double>(target - cars[i].first) / cars[i].second;
            if (time > lastTime) {
                fleet++;
                lastTime = time;
            }
        }

        return fleet;
    }
};
