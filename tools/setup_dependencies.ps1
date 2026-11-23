param([switch]$BuildRecompiler)
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
function Invoke-Git {
    param([Parameter(ValueFromRemainingArguments=$true)][string[]]$GitArguments)
    & git @GitArguments
    if ($LASTEXITCODE -ne 0) { throw "Git failed: $($GitArguments -join ' ')" }
}
$dependencies = @(
    @{ Name='N64Recomp'; Url='https://github.com/N64Recomp/N64Recomp.git'; Commit='598ce2080004a5672d604dceadbda436045307b7' },
    @{ Name='N64ModernRuntime'; Url='https://github.com/N64Recomp/N64ModernRuntime.git'; Commit='e4342ae030a9d94aa97a81aafd3368ed7daa74df' },
    @{ Name='rt64'; Url='https://github.com/rt64/rt64.git'; Commit='d9817c68ffd7328cd0af383af124971489366e18' }
)
foreach ($dep in $dependencies) {
    $path = Join-Path $root "tools/$($dep.Name)"
    if (Test-Path -LiteralPath $path) { throw "Target already exists: $path. Use a fresh checkout to avoid overwriting local changes." }
    Invoke-Git @('clone','--no-checkout',$dep.Url,$path)
    Invoke-Git @('-C',$path,'checkout','--detach',$dep.Commit)
    Invoke-Git @('-C',$path,'submodule','update','--init','--recursive')
    if ($dep.Name -eq 'N64ModernRuntime') {
        $nestedRecompiler = Join-Path $path 'N64Recomp'
        $arm32Patch = Join-Path $root 'patches/N64Recomp-arm32.patch'
        Invoke-Git @('-C',$nestedRecompiler,'apply','--check',$arm32Patch)
        Invoke-Git @('-C',$nestedRecompiler,'apply',$arm32Patch)
    }
    if ($dep.Name -eq 'N64Recomp') {
        Invoke-Git @('-C',(Join-Path $path 'lib/tomlplusplus'),'checkout','--detach','c6cbe977304c42a34ee5a553f87c9e1d53bdbc09')
    }
    $patch = Join-Path $root "patches/$($dep.Name).patch"
    if (Test-Path -LiteralPath $patch) { Invoke-Git @('-C',$path,'apply','--check',$patch); Invoke-Git @('-C',$path,'apply',$patch) }
}
if ($BuildRecompiler) {
    $recompiler = Join-Path $root 'tools/N64Recomp'
    & cmake -S $recompiler -B (Join-Path $recompiler 'build') -G Ninja -DCMAKE_BUILD_TYPE=Release
    if ($LASTEXITCODE -ne 0) { throw 'N64Recomp configuration failed.' }
    & cmake --build (Join-Path $recompiler 'build')
    if ($LASTEXITCODE -ne 0) { throw 'N64Recomp build failed.' }
}
Write-Host 'Dependencies prepared. Place your ROM at rom/chopper_attack.z64 before building.'
