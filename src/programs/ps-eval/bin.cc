#include <iostream>
#include <pokerstove/penum/ShowdownEnumerator.h>
#include <string>
#include <vector>
// #include "../../lib/pokerstove/penum/ShowdownEnumerator.h"

using namespace pokerstove;
using namespace std;

// clang-format off
//https://caniwin.com/texasholdem/preflop/heads-up.php
double preflopChart[13][13] = {
    {0.50325, 0.35980, 0.36820, 0.37835, 0.37660, 0.38145, 0.40260, 0.42410, 0.44835, 0.47375, 0.50165, 0.53200, 0.57370},
    {0.32290, 0.53680, 0.38630, 0.39680, 0.39525, 0.40030, 0.40870, 0.43255, 0.45680, 0.48225, 0.51010, 0.54050, 0.58215},
    {0.33190, 0.35135, 0.57015, 0.41450, 0.41330, 0.41840, 0.42695, 0.43850, 0.46525, 0.49060, 0.51850, 0.54875, 0.59025},
    {0.34280, 0.36255, 0.38150, 0.60320, 0.43125, 0.43665, 0.44540, 0.45715, 0.47205, 0.49985, 0.52765, 0.55785, 0.59915},
    {0.34065, 0.36065, 0.38005, 0.39940, 0.63280, 0.45360, 0.46230, 0.47425, 0.48940, 0.50600, 0.53600, 0.56635, 0.59895},
    {0.34580, 0.36590, 0.38545, 0.40505, 0.42315, 0.66230, 0.47930, 0.49115, 0.50635, 0.52320, 0.54295, 0.57530, 0.60975},
    {0.36820, 0.37470, 0.39435, 0.41425, 0.43230, 0.45045, 0.69155, 0.50790, 0.52325, 0.54010, 0.56010, 0.58310, 0.61935},
    {0.39090, 0.40010, 0.40665, 0.42660, 0.44485, 0.46295, 0.48085, 0.72050, 0.54020, 0.55660, 0.57660, 0.59980, 0.62770},
    {0.41655, 0.42585, 0.43495, 0.44240, 0.46080, 0.47895, 0.49710, 0.51525, 0.75010, 0.57520, 0.59465, 0.61780, 0.64590},
    {0.44335, 0.45265, 0.46175, 0.47175, 0.47840, 0.49675, 0.51485, 0.53240, 0.55240, 0.77465, 0.60255, 0.62560, 0.65385},
    {0.47285, 0.48210, 0.49120, 0.50110, 0.51015, 0.51760, 0.53595, 0.55355, 0.57280, 0.58125, 0.79920, 0.63390, 0.66205},
    {0.50505, 0.51420, 0.52320, 0.53310, 0.54215, 0.55180, 0.56015, 0.57800, 0.59730, 0.60565, 0.61450, 0.82385, 0.67035},
    {0.54920, 0.55835, 0.56725, 0.57690, 0.57680, 0.58830, 0.59865, 0.60760, 0.62710, 0.63555, 0.64420, 0.65310, 0.85200}
};
/* emperical
double preflopChart[13][13] = {
{0.532, 0.145, 0.151, 0.155, 0.150, 0.149, 0.151, 0.296, 0.347, 0.470, 0.523, 0.600, 0.647},
{0.148, 0.603, 0.148, 0.151, 0.153, 0.153, 0.153, 0.311, 0.401, 0.486, 0.563, 0.617, 0.695},
{0.149, 0.147, 0.639, 0.287, 0.285, 0.293, 0.305, 0.333, 0.433, 0.505, 0.583, 0.622, 0.700},
{0.151, 0.150, 0.156, 0.700, 0.323, 0.331, 0.345, 0.415, 0.471, 0.526, 0.593, 0.638, 0.711},
{0.152, 0.150, 0.151, 0.154, 0.811, 0.408, 0.422, 0.477, 0.503, 0.532, 0.611, 0.649, 0.727},
{0.152, 0.150, 0.152, 0.155, 0.306, 0.822, 0.492, 0.510, 0.534, 0.586, 0.620, 0.699, 0.735},
{0.150, 0.152, 0.151, 0.287, 0.324, 0.403, 0.845, 0.532, 0.577, 0.613, 0.632, 0.706, 0.739},
{0.152, 0.155, 0.155, 0.308, 0.344, 0.429, 0.483, 0.858, 0.599, 0.624, 0.694, 0.718, 0.818},
{0.284, 0.307, 0.328, 0.346, 0.422, 0.483, 0.520, 0.570, 0.870, 0.683, 0.708, 0.738, 0.822},
{0.341, 0.404, 0.423, 0.471, 0.486, 0.525, 0.571, 0.598, 0.616, 0.879, 0.711, 0.816, 0.829},
{0.473, 0.496, 0.512, 0.531, 0.574, 0.583, 0.613, 0.629, 0.654, 0.693, 0.892, 0.822, 0.838},
{0.536, 0.579, 0.595, 0.611, 0.625, 0.638, 0.648, 0.703, 0.717, 0.727, 0.738, 0.903, 0.844},
{0.614, 0.627, 0.644, 0.693, 0.700, 0.706, 0.715, 0.731, 0.818, 0.822, 0.828, 0.834, 0.917}};
*/

std::pair<int, int> up10[] = {
    {12, 12}, {11, 11}, {10, 10}, {9, 9},  {8, 8},   {7, 7},  {6, 6},
    {11, 12}, {5, 5},   {10, 12}, {9, 12}, {12, 11}, {8, 12}, {12, 10},
    {12, 9},  {10, 11}, {4, 4},   {7, 12}, {12, 8},  {9, 11}};

std::pair<int, int> down10[] = {{0, 2}, {6, 0}, {5, 1}, {3, 1}, {4, 1},
                                {0, 1}, {2, 1}, {5, 0}, {3, 0}, {4, 0},
                                {2, 0}, {1, 0}};
// clang-format on
std::vector<std::string>
getSuitCombinations(const std::pair<int, int> &rankPair) {
  std::string ranks = "23456789TJQKA";
  std::vector<std::string> suits = {"c", "d", "h", "s"};
  std::vector<std::string> combinations;

  if (ranks[rankPair.first] != ranks[rankPair.second])
    for (const auto &suit1 : suits) {
      for (const auto &suit2 : suits) {
        if (rankPair.first == rankPair.second && suit1 == suit2) {
          continue; // Skip same rank same suit (impossible combination)
        }
        combinations.push_back(ranks[rankPair.first] + suit1 +
                               ranks[rankPair.second] + suit2);
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

void del_range(CardDistribution &dist, string type) {
  // cout << type << endl;
  if (type == "up10")
    for (const auto &pair : up10) {
      std::vector<std::string> combinations = getSuitCombinations(pair);
      for (const auto &combination : combinations) {
        // cout << combination << endl;
        dist.removeHand(CardSet(combination));
      }
    }
  else if (type == "down10")
    for (const auto &pair : down10) {
      std::vector<std::string> combinations = getSuitCombinations(pair);
      for (const auto &combination : combinations) {
        // cout << combination << endl;
        dist.removeHand(CardSet(combination));
      }
    }
}

int getRankIndex(char rank) {
  std::string ranks = "23456789TJQKA";
  return ranks.find(rank);
}

double preflopLookup(const std::string &hand,
                     const std::vector<std::string> exclude) {
  char rank1 = hand[0];
  char suit1 = hand[1];
  char rank2 = hand[2];
  char suit2 = hand[3];
  // cout << rank1 << suit1 << endl;
  // cout << rank2 << suit2 << endl;

  int index1 = getRankIndex(rank1);
  int index2 = getRankIndex(rank2);

  double val;
  if (suit1 == suit2) {
    // Suited hand
    if (index1 > index2)
      std::swap(index1, index2); // column idx big
    val = preflopChart[index1][index2];
  } else {
    // Offsuit hand
    if (index1 < index2)
      std::swap(index1, index2); // row idx big
    val = preflopChart[index1][index2];
  }
  if (std::find(exclude.begin(), exclude.end(), "up10") != exclude.end())
    val += 0.02;
  if (std::find(exclude.begin(), exclude.end(), "down10") != exclude.end())
    val -= 0.02;
  return val;
}

double equity(const std::string &myhand, const std::string &board,
              const std::vector<std::string> &exclude) {
  if (board.empty())
    return preflopLookup(myhand, exclude);

  boost::shared_ptr<PokerHandEvaluator> evaluator =
      PokerHandEvaluator::alloc("h");
  vector<CardDistribution> handDists;

  handDists.emplace_back();
  handDists.back().parse(myhand);

  // parse opponent dead CardSets
  handDists.emplace_back();
  handDists.back().fill(evaluator->handSize());
  for (const string &ex : exclude) {
    // cout << ex << endl;
    // handDists.back().removeHand(CardSet(ex));
    if (ex == "up10" || ex == "down10")
      del_range(handDists.back(), ex);
    else if (ex.length() == 1) {
      if (ex != "c" && ex != "d" && ex != "h" && ex != "s")
        handDists.back().removeCards(
            CardSet(ex + "c" + ex + "d" + ex + "h" + ex + "s"));
    } else
      handDists.back().removeHand(CardSet(ex));
  }
  // cout << handDists.back().str() << endl;

  ShowdownEnumerator showdown;
  vector<EquityResult> results =
      showdown.calculateEquity(handDists, CardSet(board), evaluator);

  double total = 0.0;
  for (const EquityResult &result : results) {
    total += result.winShares + result.tieShares;
  }

  double equity = (results[0].winShares + results[0].tieShares) / total;

  return equity;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Usage: " << argv[0] << " <hand> [board] [exclude]" << endl;
    return 1;
  }

  string myhand = argv[1];
  string board = "";
  vector<string> exclude;
  if (argc > 2)
    board = argv[2];
  if (argc > 3) {
    for (int i = 3; i < argc; ++i) {
      exclude.push_back(argv[i]);
    }
  }

  cout << equity(myhand, board, exclude) << endl;

  return 0;
}
