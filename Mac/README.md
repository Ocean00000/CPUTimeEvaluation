# CPUTimeEvaluation

各プラットフォームで利用可能な時刻取得 API を `std::chrono` 互換のカスタムクロックとしてラップし、その**分解能（Resolution）**と**レイテンシ（Latency）**を計測・評価する C++ プロジェクトです。

## 概要

時刻取得 API は種類によって精度・コストが大きく異なります。本プロジェクトでは各 API を統一インターフェースのクロックとして実装し、以下の2指標を CSV 形式で出力することで横断的な比較を可能にします。

- **Resolution（分解能）** : クロックの値が変化する最小の時間間隔
- **Latency（レイテンシ）** : `now()` 呼び出し1回あたりの所要時間

## プロジェクト構成

| ディレクトリ | プラットフォーム | 使用 API |
|---|---|---|
| `Mac/` | macOS | `times()`（`sys/times.h`） |
| `Windows/` | Windows | `GetProcessTimes` |

### Mac

macOS の POSIX API `times()` を利用して、プロセスのカーネル時間・ユーザー時間を計測します。

詳細は [Mac/README.md](Mac/README.md) を参照してください。

### Windows（CPUTimeEvaluation）

Windows API `GetProcessTimes` を利用して、プロセスのカーネル時間・ユーザー時間を計測します。

詳細は [Windows/README.md](Windows/README.md) を参照してください。


## 出力形式

いずれのプロジェクトも、実行すると以下の CSV 形式で標準出力に結果を出力します。

```
Timer,Resolution,Unit,Latency,Unit
<クロック名>,<分解能>,<単位>,<レイテンシ>,<単位>
```
