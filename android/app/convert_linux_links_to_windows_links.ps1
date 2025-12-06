#Requires -RunAsAdministrator

function Get-LinkTarget {
    param (
        [string] $LinkPath
    )
    $file = Get-Item -Path $LinkPath
    $basePath = $File.Directory.FullName
    $relativePath = Get-Content -Path $File -TotalCount 1
    $targetPath = Resolve-Path -Path "$basePath\$relativePath"
    return $targetPath
}

# /endless-mobile/android/app
$rootDirectory = $PSScriptRoot

$links = @(
    "$rootDirectory\jni\src\SDL2"
    "$rootDirectory\src\main\java\org\libsdl"
    "$rootDirectory\src\main\assets\endless-sky-data\data"
    "$rootDirectory\src\main\assets\endless-sky-data\shaders"
    "$rootDirectory\src\main\assets\endless-sky-data\credits.txt"
)
Get-ChildItem -Path "$rootDirectory\src\main\res\mipmap*" -Recurse | ForEach-Object { $links += $_.FullName}

$links | ForEach-Object {
    New-Item -Path $_ -ItemType SymbolicLink -Value ((Get-LinkTarget -LinkPath $_).Path) -Force
}
