const SIZE = 1 << 18
const MASK = SIZE - 1
var mx, mn, lz [SIZE]int16
var lastseen [100_001]uint32
var offset, version uint32

func update(idx uint32, delta int16) {
	v := offset | idx
	for curr := v; curr > 0; {
		curr = curr>>bits.TrailingZeros32(curr) - 1
		lz[curr] += delta
	}
	for v > 1 {
		v >>= 1
		left := v << 1
		right := left | 1
		mx[v] = max(mx[left]+lz[left], mx[right]+lz[right])
		mn[v] = min(mn[left]+lz[left], mn[right]+lz[right])
	}
}

func leftmostzero() uint32 {
	curr, sum := uint32(1), int16(0)
	for curr < offset {
		sum -= lz[curr]
		curr <<= 1
		if s := sum - lz[curr]; s < mn[curr] || s > mx[curr] {
			curr |= 1
		}
	}
	return curr ^ offset
}

func longestBalanced(nums []int) int {
	version += SIZE
	var result, balance uint32
	offset = 1 << bits.Len32(uint32(len(nums)))
	for i := 0; i < len(nums); {
		num := nums[i]
		for i < len(nums) && nums[i] == num {
			i++
		}
		idx := uint32(i)
		delta := int16(num&1)<<1 - 1
		if last := lastseen[num]; last > version {
			update(last&MASK, -delta)
		} else {
            balance += uint32(delta)
        }
		update(idx, delta)
		lastseen[num] = version | idx
        if balance == 0 {
            result = idx
        } else {
		    result = max(result, idx-leftmostzero())
        }
	}
	clear(mx[:offset<<1])
	clear(mn[:offset<<1])
	clear(lz[:offset<<1])
	return int(result)
}