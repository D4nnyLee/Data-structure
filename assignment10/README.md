# Data Structure Assignment 10

F74071158
資訊 111
李韋杰

## Quick sort analysis

![test time](./testTime.png)

### Comparison of `longer first`, `shorter first` and `original`

當先遞迴長的部份時，遞迴深度較深，而 tail call 有優化到的部份是較短的部份，因此節省的時間會比較少，所以 `longer first` 都會比 `shorter first` 來的慢。

而使用 `original` 的時候因為沒有判斷長短而是直接先左半部後右半部，所以速度時好時壞。

### Comparison of `leftmost` and `median of three`

當資料中的數字順序很亂時，直接選最左邊的數當 `pivot` 的效果跟選中位數的效果是差不多的，因為 `leftmost` 不需要多餘的判斷，所以速度上 `leftmost` 會比 `median of three` 快。

但是當資料是高度排序的狀態時，`median of three` 可以避免複雜度退化成 $O(n^2)$ ，所以如果資料為高度排序時 `median of three` 會比 `leftmost` 快。
