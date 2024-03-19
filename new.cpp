#include <iostream>
#include <string>
#include <map>

// Function to trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main() {
    // JSON string
    std::string json_str = R"({"auto": true, "speed": 80, "show-time": 180})";

    // Remove whitespace
    json_str = trim(json_str);

    // Check if JSON string is enclosed in curly braces
    if (json_str.front() != '{' || json_str.back() != '}') {
        std::cerr << "Invalid JSON format: missing curly braces." << std::endl;
        return 1;
    }

    // Remove curly braces
    json_str = json_str.substr(1, json_str.size() - 2);

    // Parse JSON key-value pairs
    std::map<std::string, std::string> json_data;
    size_t pos = 0;
    while ((pos = json_str.find(',')) != std::string::npos) {
        std::string token = json_str.substr(0, pos);
        size_t colon_pos = token.find(':');
        std::string key = trim(token.substr(0, colon_pos));
        std::string value = trim(token.substr(colon_pos + 1));
        json_data[key] = value;
        json_str.erase(0, pos + 1);
    }
    // Add the last key-value pair
    size_t colon_pos = json_str.find(':');
    std::string key = trim(json_str.substr(0, colon_pos));
    std::string value = trim(json_str.substr(colon_pos + 1));
    json_data[key] = value;

    // Access parsed data
    bool auto_status = json_data["\"auto\""] == "true" ? true : false;
    int pressure_value = std::stoi(json_data["\"speed\""]);
    int showtime = std::stoi(json_data["\"show-time\""]);

    // Output results
    std::cout << "Auto status: " << std::boolalpha << auto_status << std::endl;
    std::cout << "Pressure value: " << pressure_value << std::endl;
    std::cout << "Pressure value: " << pressure_value << std::endl;

    return 0;
}