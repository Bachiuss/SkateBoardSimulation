#include "SkateboardAnimInstance.h"
#include "SkateboardGuy.h"
#include "GameFramework/CharacterMovementComponent.h"


void USkateboardAnimInstance::UpdateAnimationPropertires(float DeltaTime)
{
	// if every frame character is null we are trying to get again
	if (SkateboardGuy == nullptr)
	{
		SkateboardGuy = Cast<ASkateboardGuy>(TryGetPawnOwner());
	}
	if (SkateboardGuy)
	{
		// Get Character's Velocity
		FVector Velocity{ SkateboardGuy->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();

		// if the character is in air or not
		bIsInAir = SkateboardGuy->GetCharacterMovement()->IsFalling();

		// is Accelerating ?
		if (SkateboardGuy->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f)
		{
			bIsAccelerating = true;
		}
		else
		{
			bIsAccelerating = false;
		}
	}
}

void USkateboardAnimInstance::NativeInitializeAnimation()
{
	SkateboardGuy = Cast<ASkateboardGuy>(TryGetPawnOwner());
}
