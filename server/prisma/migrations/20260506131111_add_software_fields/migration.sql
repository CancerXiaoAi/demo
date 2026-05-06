-- RedefineTables
PRAGMA defer_foreign_keys=ON;
PRAGMA foreign_keys=OFF;
CREATE TABLE "new_Credential" (
    "id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    "platform" TEXT,
    "username" TEXT,
    "password" TEXT,
    "category" TEXT,
    "features" TEXT,
    "baseType" TEXT NOT NULL,
    "baseId" TEXT,
    "softwareName" TEXT,
    "softwareId" TEXT,
    "useBaseCredentials" BOOLEAN NOT NULL DEFAULT false,
    "remark" TEXT,
    "userId" INTEGER NOT NULL,
    "createdAt" DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "updatedAt" DATETIME NOT NULL,
    "deletedAt" DATETIME,
    CONSTRAINT "Credential_userId_fkey" FOREIGN KEY ("userId") REFERENCES "User" ("id") ON DELETE CASCADE ON UPDATE CASCADE
);
INSERT INTO "new_Credential" ("baseId", "baseType", "category", "createdAt", "deletedAt", "features", "id", "password", "platform", "remark", "updatedAt", "userId", "username") SELECT "baseId", "baseType", "category", "createdAt", "deletedAt", "features", "id", "password", "platform", "remark", "updatedAt", "userId", "username" FROM "Credential";
DROP TABLE "Credential";
ALTER TABLE "new_Credential" RENAME TO "Credential";
PRAGMA foreign_keys=ON;
PRAGMA defer_foreign_keys=OFF;
