//
//  Copyright (c) 2021 Open Whisper Systems. All rights reserved.
//

#import <SignalServiceKit/BaseModel.h>

NS_ASSUME_NONNULL_BEGIN

// We store metadata for known backup fragments (i.e.  CloudKit record) in
// the database.  We might learn about them from:
//
// * Past backup exports.
// * An import downloading and parsing the manifest of the last complete backup.
//
// Storing this data in the database provides continuity.
//
// * Backup exports can reuse fragments from previous Backup exports even if they
//   don't complete (i.e. backup export resume).
// * Backup exports can reuse fragments from the backup import, if any.
@interface OWSBackupFragment : BaseModel

@property (nonatomic) NSString *recordName;

@property (nonatomic) NSData *encryptionKey;

// This property is only set for certain types of manifest item,
// namely attachments where we need to know where the attachment's
// file should reside relative to the attachments folder.
@property (nonatomic, nullable) NSString *relativeFilePath;

// This property is only set for attachments.
@property (nonatomic, nullable) NSString *attachmentId;

// This property is only set if the manifest item is downloaded.
@property (nonatomic, nullable) NSString *downloadFilePath;

// This property is only set if the manifest item is compressed.
@property (nonatomic, nullable) NSNumber *uncompressedDataLength;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithUniqueId:(NSString *)uniqueId NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithGrdbId:(int64_t)grdbId uniqueId:(NSString *)uniqueId NS_UNAVAILABLE;

// --- CODE GENERATION MARKER

// This snippet is generated by /Scripts/sds_codegen/sds_generate.py. Do not manually edit it, instead run `sds_codegen.sh`.

// clang-format off

- (instancetype)initWithGrdbId:(int64_t)grdbId
                      uniqueId:(NSString *)uniqueId
                    attachmentId:(nullable NSString *)attachmentId
                downloadFilePath:(nullable NSString *)downloadFilePath
                   encryptionKey:(NSData *)encryptionKey
                      recordName:(NSString *)recordName
                relativeFilePath:(nullable NSString *)relativeFilePath
          uncompressedDataLength:(nullable NSNumber *)uncompressedDataLength
NS_DESIGNATED_INITIALIZER NS_SWIFT_NAME(init(grdbId:uniqueId:attachmentId:downloadFilePath:encryptionKey:recordName:relativeFilePath:uncompressedDataLength:));

// clang-format on

// --- CODE GENERATION MARKER

@end

NS_ASSUME_NONNULL_END
