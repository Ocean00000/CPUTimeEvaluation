# CPUTimeEvaluation

macOS の `times()` API（`sys/times.h`）を利用して、プロセスのカーネル時間・ユーザー時間を計測するクロック（`std::chrono` 互換のカスタムクロック）の**分解能（Resolution）**と**レイテンシ（Latency）**を評価する C++ プロジェクトです。

## 概要

本プロジェクトでは、以下の2種類のカスタムクロックを定義し、それぞれの性能を計測します。

- `times_kernel_function_clock` : プロセスのカーネルモード実行時間を返すクロック
- `times_user_function_clock` : プロセスのユーザーモード実行時間を返すクロック

実行すると、各クロックについて以下の2つの指標を計測し、CSV 形式で標準出力に出力します。

- **Resolution（分解能）** : クロックの値が変化する最小の時間間隔
- **Latency（レイテンシ）** : クロックの `now()` 呼び出し1回あたりの所要時間

## プロジェクト構成

| ファイル | 説明 |
|---|---|
| `CPUTimeEvaluation/main.cpp` | エントリポイント。計測処理と結果出力を行う |
| `CPUTimeEvaluation/FunctionClock.hpp` | `times()` を利用したカスタムクロックの定義 |
| `CPUTimeEvaluation/TimerName.hpp` | クロックの表示名を取得するユーティリティ |
| `CPUTimeEvaluation/Unit.hpp` | 計測単位の表示名を取得するユーティリティ |

## 動作環境

- macOS
- Xcode（C++17 / `gnu++17` でビルド）
- POSIX API（`sys/times.h` を使用）

## ビルドと実行

1. `CPUTimeEvaluation.xcodeproj` を Xcode で開きます。
2. プロジェクトをビルドします（Product > Build）。
3. 生成された実行ファイルを実行します（Product > Run）。

実行すると、以下のような形式で結果が標準出力に出力されます。

```
Timer,Resolution,Unit,Latency,Unit
<クロック名>,<分解能>,<単位>,<レイテンシ>,<単位>
```

## 注意事項

- 本プロジェクトは macOS（Xcode）向けに作成しています。
- ソースコードは POSIX 準拠の `times()` API のみを使用しているため、Linux など他の POSIX 環境でもビルドできる可能性がありますが、Linux 向けのビルド設定は用意しておらず、動作も確認していません。
- Windows 版は [Windows/README.md](../Windows/README.md) を参照してください。
- プロジェクト全体の説明は [README.md](../README.md) を参照してください。
