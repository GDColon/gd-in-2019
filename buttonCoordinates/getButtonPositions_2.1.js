let baseSize = [1920, 1080] // resolution of the original image
let trueSize = [569, 320] // 16:9 resolution used by GD
let ratio = [baseSize[0] / trueSize[0], baseSize[1] / trueSize[1]]

let xSpacing = 116 // x spacing between large buttons
let ySpacing = 102 // y spacing between large buttons
let middleOffset = (xSpacing / 2) * -1

// coordinates for each button in a "group"
// a group is the main list of 10 buttons (row of 3, row of 4, row of 3)
let buttonCoords = {
    create: [0, 0],
    saved: [xSpacing, 0],
    highscore: [xSpacing * 2, 0],

    challenge: [middleOffset, ySpacing],
    daily: [middleOffset + xSpacing, ySpacing],
    mapPacks: [middleOffset + (xSpacing * 2), ySpacing],
    gauntlets: [middleOffset + (xSpacing * 3), ySpacing],

    featured: [0, ySpacing * 2],
    fame: [xSpacing, ySpacing * 2],
    search: [xSpacing * 2, ySpacing * 2]
}

// geode methods to run when a button is pressed
let buttonFunctions = {
    create: "onMyLevels",
    saved: "onSavedLevels",
    highscore: "onLeaderboards",
    challenge: "onChallenge",
    daily: "onDailyLevel",
    weekly: "onWeeklyLevel",
    mapPacks: "onMapPacks",
    gauntlets: "onGauntlets",
    featured: "onFeaturedLevels",
    fame: "onFameLevels",
    search: "onOnlineLevels",
}

// spacing between each group
let baseX = 327
let spaceX = 348
let baseY = 78
let spaceY = 204

// serponge's meme consists of 12 "groups" of editor buttons
// some of these groups have certain buttons removed (e.g. the top left one has no gauntlets button)
// each entry below contains the coordinates of the create button (or where it WOULD be), and which buttons should be excluded from the group
// alternating rows use the weekly button instead of daily, since the original meme was made before weeklies existed 
let groupCoords = [
    [baseX, baseY, ["gauntlets"]],
    [baseX + spaceX, baseY, ["gauntlets"]],
    [baseX + (spaceX * 2), baseY, []],

    [baseX, baseY + spaceY, ["create", "saved", "highscore", "featured", "fame", "search", "gauntlets"], true],
    [baseX + spaceX, baseY + spaceY, ["create", "saved", "highscore", "featured", "fame", "search", "gauntlets"], true],
    [baseX + (spaceX * 2), baseY + spaceY, ["create", "saved", "highscore", "featured", "fame", "search"], true],

    [baseX, baseY + (spaceY * 2), ["gauntlets"]],
    [baseX + spaceX, baseY + (spaceY * 2), ["gauntlets"]],
    [baseX + (spaceX * 2), baseY + (spaceY * 2), []],

    [baseX, baseY + (spaceY * 3), ["create", "saved", "highscore", "gauntlets"], true],
    [baseX + spaceX, baseY + (spaceY * 3), ["create", "saved", "highscore", "gauntlets"], true],
    [baseX + (spaceX * 2), baseY + (spaceY * 3), ["create", "saved", "highscore"], true]
]

// converts a button group into individual buttons, and gets their true gd coordinates
function createButtonGroup(x, y, exclude=[], useWeekly) {
    let btns = []
    for (const [id, pos] of Object.entries(buttonCoords)) {
        if (!exclude.includes(id)) {
            let trueID = id
            if (useWeekly && id == "daily") trueID = "weekly"
            btns.push({id: trueID, pos: getTrueCoords([pos[0] + x, pos[1] + y])})
        }
    }
    return btns
}

// converts 1920x1080 coordinates to weird cocos coordinates where y=0 is the bottom of the screen
function getTrueCoords(pos=[]) {
    let x = pos[0] / ratio[0]
    let y = trueSize[1] - (pos[1] / ratio[1])
    return [x, y].map(x => x.toFixed(3))
}

// where the locks in the original meme are
let lockCoords = [
    [1798, 22],
    [1671, 22],
    [1551, 141],
    [1672, 141],
    [1800, 142],
    [1553, 262],
    [1678, 262]
].map(x => getTrueCoords(x))

// where the doors in the original meme are
let doorCoords = [
    [1754, 926],
    [1607, 957],
    [1450, 736],
    [1659, 790],
    [1819, 757],
    [1662, 535],
    [1466, 570],
    [1588, 808]
].map(x => getTrueCoords(x))

let finalButtonList = []
groupCoords.forEach(x => {
    let group = createButtonGroup(...x)
    group.forEach(b => finalButtonList.push(b))
})

let allBigButtons = finalButtonList.map(x => `buttonList->addChild(makeLargeButton("${x.id}", ${x.pos[0]}f, ${x.pos[1]}f, menu_selector(CreatorLayer::${buttonFunctions[x.id]})));`).join("\n")
let allLocks = lockCoords.map(x => `buttonList->addChild(cloneBtn(${x[0]}f, ${x[1]}f, vaultButton, vaultOffset));`).join("\n")
let allDoors = doorCoords.map(x => `buttonList->addChild(cloneBtn(${x[0]}f, ${x[1]}f, doorButton, doorOffset));`).join("\n")

// copy and paste this into the cpp code lol
console.log(allBigButtons + "\n")
console.log(allLocks + "\n")
console.log(allDoors)