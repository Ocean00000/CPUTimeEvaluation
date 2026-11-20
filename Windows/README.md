# CPUTimeEvaluation

Windows の `GetProcessTimes` API を利用して、プロセスのカーネル時間・ユーザー時間を計測するクロック（`std::chrono` 互換のカスタムクロック）の分解能（Resolution）とレイテンシ（Latency）を評価する C++ プロジェクトです。

## 概要

本プロジェクトでは、以下の2種類のカスタムクロックを定義し、それぞれの性能を計測します。

- `GetProcessTimes_kernel_function_clock` : プロセスのカーネルモード実行時間を返すクロック
- `GetProcessTimes_user_function_clock` : プロセスのユーザーモード実行時間を返すクロック

実行すると、各クロックについて以下の2つの指標を計測し、CSV形式で標準出力に出力します。

- **Resolution（分解能）** : クロックの値が変化する最小の時間間隔
- **Latency（レイテンシ）** : クロックの `now()` 呼び出し1回あたりの所要時間

## プロジェクト構成

| ファイル | 説明 |
|---|---|
| `CPUTimeEvaluation/CPUTimeEvaluation.cpp` | エントリポイント。計測処理と結果出力を行う |
| `CPUTimeEvaluation/FunctionClock.hpp` | `GetProcessTimes` を利用したカスタムクロックの定義 |
| `CPUTimeEvaluation/TimerName.hpp` | クロックの表示名を取得するユーティリティ |
| `CPUTimeEvaluation/Unit.hpp` | 計測単位の表示名を取得するユーティリティ |

## 動作環境

- Windows
- Visual Studio（C++17 以上を想定）
- Windows SDK（`Windows.h`, `processthreadsapi.h` を使用）

## ビルドと実行

1. `CPUTimeEvaluation.sln`（または `.vcxproj`）を Visual Studio で開きます。
2. ソリューションをビルドします。
3. 生成された実行ファイルを実行します。

実行すると、以下のような形式で結果が標準出力に出力されます。

```
Timer,Resolution,Unit,Latency,Unit
<クロック名>,<分解能>,<単位>,<レイテンシ>,<単位>
```

## 注意事項

- 計測中はプロセスの優先度を `ABOVE_NORMAL_PRIORITY_CLASS` に引き上げ、計測後に `NORMAL_PRIORITY_CLASS` に戻します。これは計測精度を上げるための措置です。
- 本プロジェクトは Windows 固有の API に依存しているため、他プラットフォームでは動作しません。
