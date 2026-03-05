from dataclasses import dataclass


@dataclass
class GroupInfo:
    characters_count: int
    binary_value_character: str


class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        # Use two groups of start index and binary value characters count track
        # current adjacent two groups of consecutive 1s and consecutive 0s,
        # and update number of valid substrings dynamically.
        if not s:
            return 0

        s_iterator = iter(s)
        current_group_info = GroupInfo(
            characters_count=1,
            binary_value_character=next(s_iterator)
        )
        previous_group_info = GroupInfo(
            characters_count=0,
            binary_value_character='0'
        )
        substrings_count = 0

        for binary_value_character in s_iterator:
            if (
                binary_value_character
                ==
                current_group_info.binary_value_character
            ):
                # If current binary value character is as same as the recorded value
                # in the current group, just increase binary value character count
                # recorded in the current group by 1.
                current_group_info.characters_count += 1
            else:
                # If current binary value characters is different than the one
                # recorded in the current group, it menas there is bit value
                # character change (1->0 or 0->1) starting from current index,
                # we need to preserve the original current group information
                # to another group and update current group information.

                # Copy current group info struct to another group info struct
                # that is used to preserve original current group information.
                previous_group_info.characters_count = \
                    current_group_info.characters_count
                previous_group_info.binary_value_character = \
                    current_group_info.binary_value_character

                # Update current group information.
                current_group_info.characters_count = 1
                current_group_info.binary_value_character = \
                    binary_value_character

            # If the binary value characters count recorded in the previous
            # group is greater than or equal to the binary characters count
            # recorded in the current group, it means there is a new substring
            # can be formed.
            if (
                previous_group_info.characters_count
                >=
                current_group_info.characters_count
            ):
                substrings_count += 1

        return substrings_count
