let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 1 then
    float_of_int (List.nth sorted (n/2))
  else
    let a = List.nth sorted (n/2 - 1) in
    let b = List.nth sorted (n/2) in
    (float_of_int (a + b)) /. 2.0

let mode lst =
  let tbl = List.fold_left
    (fun acc x ->
      let count = try List.assoc x acc + 1 with Not_found -> 1 in
      (x, count) :: List.remove_assoc x acc)
    [] lst
  in
  let max_count = List.fold_left (fun m (_,c) -> max m c) 0 tbl in
  tbl
  |> List.filter (fun (_,c) -> c = max_count)
  |> List.map fst

(* Sample run *)
let () =
  let data = [1;2;2;3;4] in
  Printf.printf "Mean:   %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode:   %s\n"
    (String.concat " " (List.map string_of_int (mode data)))
