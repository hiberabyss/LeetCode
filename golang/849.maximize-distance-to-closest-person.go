package main
/*
 * [879] Maximize Distance to Closest Person
 *
 * https://leetcode.com/problems/maximize-distance-to-closest-person/description/
 *
 * algorithms
 * Easy (39.54%)
 * Total Accepted:    12K
 * Total Submissions: 31.4K
 * Testcase Example:  '[1,0,0,0,1,0,1]'
 *
 * In a row of seats, 1 represents a person sitting in that seat, and 0
 * represents that the seat is empty. 
 * 
 * There is at least one empty seat, and at least one person sitting.
 * 
 * Alex wants to sit in the seat such that the distance between him and the
 * closest person to him is maximized. 
 * 
 * Return that maximum distance to closest person.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation: 
 * If Alex sits in the second open seat (seats[2]), then the closest person has
 * distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,0,0,0]
 * Output: 3
 * Explanation: 
 * If Alex sits in the last seat, the closest person is 3 seats away.
 * This is the maximum distance possible, so the answer is 3.
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= seats.length <= 20000
 * seats contains only 0s or 1s, at least one 0, and at least one 1.
 * 
 * 
 * 
 * 
 */

func max(x, y int) int {
    if x >= y {
        return x
    }

    return y
}

func maxDistToClosest(seats []int) int {
	N := len(seats)
	if N < 2 {
		return 0
	}

	i := 0
	maxDis := 1
	lastPos := -1

	for ;; {
		for i < N && seats[i] == 0 {
			i++
		}

		if i >= N {
			if lastPos < 0 {
				return 0
			}

			return max(maxDis, i - lastPos - 1)
		}

		if lastPos < 0 {
			maxDis = max(maxDis, i)
		} else {
			maxDis = max(maxDis, (i-lastPos)/2)
		}
		lastPos = i
		i++
	}

	return maxDis
}
