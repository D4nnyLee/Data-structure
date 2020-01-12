# Data Structure HW9

F74071158
資訊111
李韋杰

## Active On Edge (AOE) Network

### Algorithm

#### (a)

Use a queue to store all vertices that are unvisited and not connected by any unfinished activity.

Then iterate all vertices in the queue to calculate the time of `Early Event`.

During the iteration, if there is any new vertex meet the condition above, the vertex also should be push into the queue.

After calculating `Early Event`, then we should calculate `Last Event`.

We iterate all vertices in the reverse order of that of `Early Event`.

#### (b)

for each activity `i`
`u` = begin of `i`
`v` = end of `i`
`w` = duration of `i`
`Early Time` = `u`'s `Early Event`
`Late Time` = `v`'s `Late Event` - `w`
`Slack` = `Late Time` - `Early Time`

#### (c)

All activities whose `Slack` = 0
