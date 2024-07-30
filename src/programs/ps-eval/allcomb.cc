#include <iostream>
#include <string>
#include <vector>

int getRankIndex(char rank) {
  std::string ranks = "23456789TJQKA";
  return ranks.find(rank);
}

std::vector<std::pair<int, int>>
convertHandsToPairs(const std::vector<std::string> &hands) {
  std::vector<std::pair<int, int>> pairs;

  for (const auto &hand : hands) {
    int rank1 = getRankIndex(hand[0]);
    int rank2 = getRankIndex(hand[1]);
    bool suited = hand[2] == 's';

    if (suited) {
      pairs.push_back(
          std::make_pair(std::min(rank1, rank2), std::max(rank1, rank2)));
    } else {
      pairs.push_back(
          std::make_pair(std::max(rank1, rank2), std::min(rank1, rank2)));
    }
  }

  return pairs;
}

std::vector<std::string>
getSuitCombinations(const std::pair<int, int> &rankPair) {
  std::string ranks = "23456789TJQKA";
  std::vector<std::string> suits = {"c", "d", "h", "s"};
  std::vector<std::string> combinations;

  if(ranks[rankPair.first] != ranks[rankPair.second])
	  for (const auto& suit1 : suits) {
			for (const auto& suit2 : suits) {
				if (rankPair.first == rankPair.second && suit1 == suit2) {
					continue; // Skip same rank same suit (impossible combination)
				}
				combinations.push_back(ranks[rankPair.first] + suit1 + ranks[rankPair.second] + suit2);
			}
		}
	else
	  for (int i = 0; i < 4; ++i) {
		std::string suit1 = suits[i];
		for (int j = i; j < 4; ++j) {
		  std::string suit2 = suits[j];
		  if (rankPair.first == rankPair.second && suit1 == suit2) {
			continue; // Skip same rank same suit (impossible combination)
		  }
		  combinations.push_back(ranks[rankPair.first] + suit1 +
								 ranks[rankPair.second] + suit2);
		}
	  }

  return combinations;
}

int main() {
  std::vector<std::string> hands = {
      "AAo", "KKo", "QQo", "JJo", "TTo", "99o", "88o", "AKs", "77o", "AQs",
      "AJs", "AKo", "ATs", "AQo", "AJo", "KQs", "66o", "A9s", "ATo", "KJs"};

  std::vector<std::pair<int, int>> pairs = convertHandsToPairs(hands);

  for (const auto &pair : pairs) {
    std::vector<std::string> combinations = getSuitCombinations(pair);
    for (const auto &combination : combinations) {
      std::cout << '"'<<combination <<'"' ;
    }
  }

  return 0;
}
