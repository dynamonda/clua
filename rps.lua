-- rps.lua
-- じゃんけんスクリプト
-- p.269

--[[乱数発生機]]
math.randomseed(os.time())

--[[プレイヤーとコンピュータのスコア]]
user_score = 0
comp_score = 0

--[[どのラウンドで誰が勝ったかを決定するのに使われる]]
lookup = {}
lookup["rock"] = { rock = "draw", paper = "lose", scissors = "win" }
lookup["paper"] = { rock = "win", paper = "draw", scissors = "lose" }
lookup["scissors"] = { rock = "lose", paper = "win", scissors = "draw" }

--[[ コンピュータの最善の予測結果を返す ]]
function GetAIMove()

    -- 整数をじゃんけんの手に変換する
    local int_to_name = {"scissors", "rock", "paper"}
    
    -- 1-3のランダムな整数を取得し、この関数がランダムな手を返すことができるように
    -- 表のインデックスとする。
    return int_to_name[math.random(3)]
end

--[[ この関数は参照表を用いて勝者を決定し、それに基づいてスコアを割り当てる]]
function EvaluateTheGuesses(user_guess, comp_guess)

    print("user guess... "..user_guess.." comp guess... "..comp_guess)

    if (lookup[user_guess][comp_guess] == "win") then
        print("You win the Round!")
        user_score = user_score + 1
    elseif (lookup[user_guess][comp_guess] == "lose") then
        print("Computer wins the Round!")
        comp_score = comp_score + 1
    else
        print("Draw!")
        print(lookup[user_guess][comp_guess])
    end
end

--[[ ゲームのメインループ ]]
print("Enter q to quit game")
print()

loop = true
while loop == true do

    -- ユーザーに現在のスコアを知らせる
    print("User: "..user_score.." Computer: "..comp_score)

    -- キーボードから入力を取得する
    user_guess = io.stdin:read '*l'

    -- ユーザーの入力を文字列に変換する表を宣言する
    local letter_to_string = {s="scissors", r="rock", p="paper"}

    if user_guess == "q" then
        loop = false
    elseif (user_guess == "r") or (user_guess == "p") or (user_guess == "s") then
        comp_guess = GetAIMove()
        EvaluateTheGuesses(letter_to_string[user_guess], comp_guess)
    else
        print("Invalid input, try again")
    end
end
