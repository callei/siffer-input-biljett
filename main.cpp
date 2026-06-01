#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct PricingConfig {
  int childMaxAge = 11;
  int seniorMinAge = 66;
  int discountPrice = 20;
  int normalPrice = 30;
  string prompt = "Hur gammal är du?";
  string invalidInput = "Felaktig inmatning";
};

bool isValidIntegerString(const string& value) {
  if (value.empty()) {
    return false;
  }

  for (size_t i = 0; i < value.size(); ++i) {
    if (value[i] < '0' || value[i] > '9') {
      return false;
    }
  }

  return true;
}

bool tryParseNonNegativeInt(const string& value, int& result) {
  size_t pos = 0;
  try {
    result = stoi(value, &pos);
  } catch (...) {
    return false;
  }

  if (pos != value.size() || result < 0) {
    return false;
  }

  return true;
}

int calculatePrice(int age, const PricingConfig& config) {
  if (age <= config.childMaxAge || age >= config.seniorMinAge) {
    return config.discountPrice;
  }
  return config.normalPrice;
}

int main() {

  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  PricingConfig config;
  cout << config.prompt << endl;

  string s_heltal; 
  cin >> s_heltal;

  int heltal = 0;
  if (!isValidIntegerString(s_heltal) || !tryParseNonNegativeInt(s_heltal, heltal)) {
    cout << config.invalidInput << endl;
    return 0;
  }

  int price = calculatePrice(heltal, config);
  cout << "Det blir " << price << " kr att betala" << endl;

 return 0;
}
