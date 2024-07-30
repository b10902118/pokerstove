#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int getRankIndex(char rank)
{
	std::string ranks = "23456789TJQKA";
	return ranks.find(rank);
}

std::vector<std::pair<int, int>> convertHandsToPairs(const std::vector<std::string> &hands)
{
	std::vector<std::pair<int, int>> pairs;

	for (const auto &hand : hands)
	{
		int rank1 = getRankIndex(hand[0]);
		int rank2 = getRankIndex(hand[1]);
		bool suited = hand[2] == 's';

		if (suited)
		{
			pairs.push_back(std::make_pair(std::min(rank1, rank2), std::max(rank1, rank2)));
		}
		else
		{
			pairs.push_back(std::make_pair(std::max(rank1, rank2), std::min(rank1, rank2)));
		}
	}

	return pairs;
}

int main()
{
	std::vector<std::string> hands = {
		"42s", "82o", "73o", "53o", "63o", "32s", "43o", "72o", "52o", "62o", "42o", "32o"};

	std::vector<std::pair<int, int>> pairs = convertHandsToPairs(hands);

	std::cout << "std::pair<int, int> handPairs[] = {";
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		std::cout << "{" << pairs[i].first << ", " << pairs[i].second << "}";
		if (i < pairs.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "};" << std::endl;

	return 0;
}
