#!/bin/sh
patchName="aapt.1.patch"
rm -rf $(pwd)/$patchName
diff -uN ./src ./src_org > $patchName
echo "out: $(pwd)/$patchName"
echo ">>>>> Okey <<<<<"