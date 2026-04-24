from typing import List


class Solution:
    def twoEditWords(
        self,
        queries: List[str],
        dictionary: List[str]
    ) -> List[str]:
        answer_list = list()

        for query_word in queries:
            # Try every word in the queries list with every word in the target
            # list to check if current query word can be converted to one of
            # word in the target list by changing at most two characters.
            for target_word in dictionary:
                edits_count = 0

                for c1, c2 in zip(query_word, target_word):
                    # Iterate queries[i] and dictionary[j] to check if we can
                    # convert queries[i] to dictionary[j] by changing at most
                    # two characters in queries[i].
                    if c1 != c2:
                        edits_count += 1

                    if edits_count > 2:
                        # Break checking process if count of the characters to
                        # be changed is greater than 2.
                        break
                else:
                    # Current query word can be converted to one of word in the
                    # target list by changing at most two characters.

                    # Add current word to answer list.
                    answer_list.append(query_word)

                    # Break inner loop since we already find a proper target
                    # word for current query word.
                    break

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [['word', 'note', 'ants', 'wood'], ['wood', 'joke', 'moat']],
        [['yes'], ['not']],
    ]

    for testcase in testcases_list:
        print(sol.twoEditWords(*testcase))
