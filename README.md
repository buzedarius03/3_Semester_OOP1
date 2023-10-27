# Assignment Repository for OOP1 winter term 2023

## Assignment

You can find the published assignments [here](https://gitlab.tugraz.at/oop1_ws/ws2023/specification)

## Setup: Einrichten & Ausführen des Codes

### Ordner-Struktur

Wir geben eine grundlegende Ordner-Struktur vor:

- **framework** und **testsystem** enthält den von uns zur Verfügung gestellten Code.
- **src** enthält die von Ihnen erstellten *.cpp und *.hpp Sourcecode-Dateien.
- **build** enthält die von CMake generierten Dateien und die erstellten Binaries
- `.clang-format` ist eine Implementierung des Coding-Standards für `clang-format`
- `CMakeLists.txt` ist das CMake-Buildfile.
- `runTests.*` ist ein Script, um die Testcases lokal auszuführen.
- `setup.*` lädt unseren vorgegebenen Code erstmals herunter.
- `update.*` lädt die neueste Version unseres Frameworks herunter.

#### Der 'framework'-Ordner

Das Framework beinhaltet die Server-Klasse sowie eine Klasse zum Mischen von Plättchen.
Eine genaue Beschreibung der Funktionen finden Sie unter [Framework](Framework.md).

### setup.\* und update.\*

**Bevor Sie beginnen** zu programmieren, **müssen Sie das `setup`-Script ausführen.**
Unter Windows verwenden Sie `setup.bat`, unter Linux `setup.sh`.

Weiters sollten Sie **in regelmäßigen Abständen** oder wenn eine **Änderung** an den von
uns erstellten Klassen angekündigt wurde **das `update`-Script ausführen**.
Unter Windows verwenden Sie `update.bat`, unter Linux `update.sh`.

> _**Hinweis:**_
> Sollten Sie darauf vergessen das `setup`-Script auszuführen, so können Sie die
> von uns bereitgestellten Klassen nicht nutzen. Weiters enthalten die von uns
> herausgebrachten Änderungen, die Sie mit dem `update`-Script abrufen, Bug-Fixes.
> Falls Sie also eine alte Version verwenden, kann dies zu Fehlern führen.
> Getestet wird Ihr Programm nur mit der neuesten Version der von uns zur Verfügung
> gestellten Klassen.

## Kompilieren des Projektes

Wir stellen ein CMake-File zur Verfügung (`CMakeLists.txt`).

**Vorbereitung für das Kompilieren:** (Muss nur 1x ausgeführt werden)

1. Navigieren Sie zum Hauptverzeichnis ihres geklonten Git-Repositories.
2. Erstellen Sie einen **build**-Ordner mittels `mkdir build`. 
3. Navigieren Sie in diesen Ordner mittels `cd build`.
4. Führen Sie nun `cmake ..` aus, damit ein für Ihr Betriebssystem passendes Buildfilde generiert wird.

**Code Kompilieren**: 

Um den Code nun zu kompilieren müssen Sie einfach innerhalb des angelegten **build**-Ordner den Befehl `cmake --build .` ausführen.

Für mehr Details zu CMake siehe die [Dokumentation von CMake](https://cmake.org/documentation/).

>_**Tipp:**_
>Viele IDEs und Texteditoren besitzen cmake-Support. - Entweder nativ oder durch Plugins. Verwenden Sie diesen! 
> Sie sollten dabei kein anderes Target als das automatisch ausgewählte Standard-Target `all` benötigen.

Das kompilierte Programm finden Sie in Ihrem **build**-Ordner unter dem Namen `cascadia-server`.

## Hinzufügen neuer .cpp Datein

Wenn neue Code-Datein (`.cpp`) zum Projekt hinzufügt werden, muss dies dem Buildsystem mitgeteilt werden.
Verschieben Sie dafür Ihre neu angelegte `.cpp` - Datein in den Ordner `src`.
Nun muss die Datei `CMakeLists.txt` **im Hauptverzeichnis** des Repositories angepasst werden, indem Sie den relativen Pfad zur neuen Code-Datei `src/[filename].cpp` an die gekennzeichnete Stelle des Codes hinzufügen.

Beispielauszug: 

```cpp
...

set(SOURCES src/main.cpp # Add you other source files here, simply one per line
src/my_file.cpp
src/my_other_file.cpp
)
...
```

Sobald Sie das nächste Mal `cmake --build .` ausführen, werden diese Änderung übernommen.

## clang-format

Clang-Format ist ein Tool zum Sourcecode-Formatieren.

Mit `clang-format [file]` wird die Datei in das vorgegebene Format gebracht.
Mit `clang-format --dry-run [file]` werden die Änderungen nicht vorgenommen,
nur angezeigt.

> _**Tipp:**_
> Viele IDEs und Texteditoren besitzen clang-format-Support. - Entweder nativ oder durch Plugins.

Für mehr Details siehe die [Dokumentation von Clang-Format](http://clang.llvm.org/docs/ClangFormat.html).

> _**Wichtig:**_
> Unser [Codingstandard](https://gitlab.tugraz.at/oop1_ws/ws2023/specification/CodeFormatting.md) ist mit clang-format festgelegt, also verwenden Sie das bereitgestellte clang-format-File! - Abweichungen können zu Abzügen führen!

## Testcases

Die zur Verfügung gestellten Testcases dienen zum eigenen Testen des Codes.

Sie können über die `runTests.*` Scripts ausgeführt werden.
Dies geschieht über die Kommandozeilen-Eingabe `runTests.* [AssignmentNummer]` im Basisverzeichnis Ihres Repositories.

> _**Hinweis:**_
> Neben den bereitgestellten Testcases gibt es noch einige weitere, geheime Testcases.
> Achten Sie also bei der Überprüfung der Richtigkeit Ihres Programms nicht nur
> auf die Resultate der Testcases.